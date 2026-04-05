#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "nodes/SFXIndexPopup.hpp"
#include <Geode/utils/file.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

FMOD::Channel* playingChannel = nullptr;
std::map<std::string, FMOD::Sound*> selectedOnlineSounds;
std::vector<std::string> selectedOnlineSoundPaths;

bool deathSoundEnabled = true;
bool levelCompleteEnabled = false;

FMOD::Sound* levelCompleteSound = nullptr;
std::string levelCompleteSoundPath;

std::mt19937 soundRng;

class $modify(MyPauseLayer, PauseLayer) {
public:
    void customSetup() {
        PauseLayer::customSetup();

        auto menu = getChildByID("left-button-menu");
        if (menu) {
            auto sprite = CircleButtonSprite::create(
                CCSprite::createWithSpriteFrameName("edit_eSFXBtn_001.png"),
                CircleBaseColor::DarkAqua,
                CircleBaseSize::Medium
            );

            auto button = CCMenuItemSpriteExtra::create(
                sprite,
                this,
                menu_selector(MyPauseLayer::onSFXLibrary)
            );
            menu->addChild(button);
            menu->updateLayout();
        }
    }

    void onSFXLibrary(CCObject* sender) {
        SFXIndexPopup::create(true)->show();
    }
};

namespace {
	std::filesystem::path makeUniqueDestinationPath(std::filesystem::path const& targetDir, std::filesystem::path const& originalName) {
		auto candidate = targetDir / originalName.filename();
		if (!std::filesystem::exists(candidate)) {
			return candidate;
		}

		auto stem = candidate.stem().string();
		auto ext = candidate.extension().string();
		for (int i = 1;; ++i) {
			auto suffixed = targetDir / fmt::format("{}-{}{}", stem, i, ext);
			if (!std::filesystem::exists(suffixed)) {
				return suffixed;
			}
		}
	}

	std::optional<std::filesystem::path> moveFileToDownloadedSfx(std::filesystem::path const& sourcePath, std::filesystem::path const& targetDir) {
		if (!std::filesystem::exists(sourcePath) || !std::filesystem::is_regular_file(sourcePath)) {
			return std::nullopt;
		}

		std::error_code ec;
		std::filesystem::create_directories(targetDir, ec);
		if (ec) {
			return std::nullopt;
		}

		auto destinationPath = makeUniqueDestinationPath(targetDir, sourcePath.filename());

		std::filesystem::rename(sourcePath, destinationPath, ec);
		if (ec) {
			ec.clear();
			std::filesystem::copy_file(sourcePath, destinationPath, std::filesystem::copy_options::none, ec);
			if (ec) {
				return std::nullopt;
			}

			ec.clear();
			std::filesystem::remove(sourcePath, ec);
			if (ec) {
				return std::nullopt;
			}
		}

		return destinationPath;
	}

	bool isIgnoredLegacySettingPath(std::string const& value) {
		if (value.empty()) {
			return true;
		}

		auto filename = std::filesystem::path(value).filename().string();
		return filename == "explode_11.ogg";
	}

	void migrateLegacyPathSettingToDownloadedSfx(Mod* mod, std::string_view settingKey, std::filesystem::path const& targetDir) {
		if (!mod->hasSetting(settingKey)) {
			return;
		}

		auto configuredPath = mod->getSettingValue<std::string>(settingKey);
		if (isIgnoredLegacySettingPath(configuredPath)) {
			return;
		}

		auto movedPath = moveFileToDownloadedSfx(std::filesystem::path(configuredPath), targetDir);
		if (movedPath) {
			mod->setSettingValue<std::string>(settingKey, movedPath->string());
		}
	}

	void migrateLegacyExtraSoundsFolder(Mod* mod, std::filesystem::path const& targetDir) {
		if (!mod->hasSetting("extra-sounds-path")) {
			return;
		}

		auto extraSoundsPath = mod->getSettingValue<std::string>("extra-sounds-path");
		if (extraSoundsPath.empty()) {
			return;
		}

		std::filesystem::path legacyDir(extraSoundsPath);
		if (!std::filesystem::exists(legacyDir) || !std::filesystem::is_directory(legacyDir)) {
			return;
		}

		for (auto const& entry : std::filesystem::directory_iterator(legacyDir)) {
			if (!entry.is_regular_file()) {
				continue;
			}

			moveFileToDownloadedSfx(entry.path(), targetDir);
		}

		std::error_code ec;
		std::filesystem::remove_all(legacyDir, ec);
	}

	void runFirstTimeV2Migration() {
		auto mod = Mod::get();
		auto targetDir = mod->getConfigDir() / "downloaded-sfx";

		migrateLegacyExtraSoundsFolder(mod, targetDir);
		migrateLegacyPathSettingToDownloadedSfx(mod, "sound-path", targetDir);
	}
}

std::filesystem::path transcodeLoadedSoundIfNeeded(std::filesystem::path const& originalPath) {
	return deathsounds::utils::ensurePlayableSfxPath(originalPath);
}

bool pathMatchesCue(gd::string const& path, std::string_view cue) {
	auto pathString = std::string(path);
	if (pathString.find(cue) != std::string::npos) {
		return true;
	}

	auto filename = std::filesystem::path(pathString).filename().string();
	return filename == cue || filename.find(cue) != std::string::npos;
}

void seedSoundRngFromUnixMs() {
	auto now = std::chrono::system_clock::now();
	auto unixMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
	soundRng.seed(static_cast<std::mt19937::result_type>(unixMs));
	log::info("Seeded sound RNG with unix ms: {}", unixMs);
}

void reloadSelectedOnlineSounds() {
	for (auto& [_, sound] : selectedOnlineSounds) {
		if (sound) sound->release();
	}
	selectedOnlineSounds.clear();

	auto selected = deathsounds::utils::getUsedOnlineSfxPaths();
	selectedOnlineSoundPaths = selected;

	for (auto const& pathStr : selected) {
		std::filesystem::path path(pathStr);
		if (!std::filesystem::exists(path)) {
			continue;
		}

		auto playablePath = path;
		FMOD::Sound* sound = nullptr;
		if (FMODAudioEngine::sharedEngine()->m_system->createSound(playablePath.string().c_str(), FMOD_DEFAULT, nullptr, &sound) != FMOD_OK) {
			playablePath = transcodeLoadedSoundIfNeeded(path);
			if (playablePath == path || FMODAudioEngine::sharedEngine()->m_system->createSound(playablePath.string().c_str(), FMOD_DEFAULT, nullptr, &sound) != FMOD_OK) {
				continue;
			}
		}

		if (sound) {
			selectedOnlineSounds[playablePath.string()] = sound;
		}
	}

	log::info("Selected online SFX pool size: {}", selectedOnlineSounds.size());
}

void refreshSelectedOnlineSoundsIfNeeded() {
	auto selected = deathsounds::utils::getUsedOnlineSfxPaths();
	if (selected == selectedOnlineSoundPaths) {
		return;
	}
	reloadSelectedOnlineSounds();
}

void reloadSounds() {
	for (auto& [_, sound] : selectedOnlineSounds) {
		if (sound) sound->release();
	}
	selectedOnlineSounds.clear();

	log::info("Reloading death sound(s)");
	reloadSelectedOnlineSounds();
}

$execute {
	seedSoundRngFromUnixMs();
	deathSoundEnabled = Mod::get()->getSettingValue<bool>("death-sound-enabled");
	reloadSounds();

	levelCompleteEnabled = Mod::get()->getSettingValue<bool>("level-complete-enabled");
	auto levelCompletePath = Mod::get()->getSettingValue<std::filesystem::path>("level-complete-path");
	log::info("Level complete enabled: {}", levelCompleteEnabled);
	log::info("Level complete path: {}", levelCompletePath.string());
	if (!levelCompletePath.empty() && std::filesystem::exists(levelCompletePath)) {
		log::info("Loading level-complete sound from: {}", levelCompletePath.string());
		if (FMODAudioEngine::sharedEngine()->m_system->createSound(levelCompletePath.string().c_str(), FMOD_DEFAULT, nullptr, &levelCompleteSound) != FMOD_OK) {
			log::error("Failed to load level-complete sound!");
			levelCompleteSound = nullptr;
		} else {
			log::info("Successfully loaded level-complete sound!");
			levelCompleteSoundPath = levelCompletePath.string();
		}
	} else {
		log::warn("Level complete path doesn't exist or is empty: {}", levelCompletePath.string());
	}

	listenForSettingChanges<bool>("death-sound-enabled", [](bool value) {
		deathSoundEnabled = value;
		reloadSounds();
	});

	listenForSettingChanges<std::filesystem::path>("level-complete-path", [](std::filesystem::path const& value) {
		log::info("level-complete-path changed to: {}", value.string());
		if (levelCompleteSound) {
			log::info("Releasing old level-complete sound");
			levelCompleteSound->release();
			levelCompleteSound = nullptr;
		}
		levelCompleteSoundPath.clear();

		if (!value.empty() && std::filesystem::exists(value)) {
			log::info("Loading new level-complete sound from: {}", value.string());
			if (FMODAudioEngine::sharedEngine()->m_system->createSound(value.string().c_str(), FMOD_DEFAULT, nullptr, &levelCompleteSound) != FMOD_OK) {
				log::error("Failed to load new level-complete sound!");
				levelCompleteSound = nullptr;
			} else {
				log::info("Successfully loaded new level-complete sound!");
				levelCompleteSoundPath = value.string();
			}
		} else {
			log::warn("New level-complete path doesn't exist or is empty: {}", value.string());
		}
	});

	listenForSettingChanges<bool>("level-complete-enabled", [](bool value) {
		log::info("level-complete-enabled changed to: {}", value);
		levelCompleteEnabled = value;
	});
}

class $modify(FMODAudioEngine) {
	int playEffect(gd::string path, float speed, float p2, float volume) {
		if (pathMatchesCue(path, "explode_11.ogg") || pathMatchesCue(path, "endStart_02.ogg")) {
			log::info("playEffect hook hit for {}", std::string(path));
		}

		if (pathMatchesCue(path, "explode_11.ogg")) {
			refreshSelectedOnlineSoundsIfNeeded();

			if (deathSoundEnabled && !selectedOnlineSounds.empty()) {
				std::uniform_int_distribution<size_t> soundDist(0, selectedOnlineSounds.size() - 1);

				auto it = selectedOnlineSounds.begin();
				std::advance(it, soundDist(soundRng));

				FMOD::Sound* sound = it->second;

				float minPitch = Mod::get()->getSettingValue<double>("pitch-minimum");
				float maxPitch = Mod::get()->getSettingValue<double>("pitch-maximum");
				float pitch = speed;
				if (maxPitch > minPitch) {
					std::uniform_real_distribution<float> pitchDist(minPitch, maxPitch);
					pitch = pitchDist(soundRng);
				} else {
					pitch = minPitch;
				}

				float customVolume = Mod::get()->getSettingValue<double>("volume");

				if (!Mod::get()->getSettingValue<bool>("clear-on-reset")) {
					FMOD_RESULT result = m_system->playSound(sound, nullptr, false, &playingChannel);
					if (result == FMOD_OK && playingChannel) {
						playingChannel->setVolume(customVolume * getEffectsVolume());
						playingChannel->setPitch(pitch);
					}
					else {
						log::error("playSound returned error!");
					}

					return 1;
				}
				else {
					return FMODAudioEngine::playEffect(it->first, pitch, p2, customVolume);
				}
			}
		} else if (pathMatchesCue(path, "endStart_02.ogg")) {
			log::info("Level complete sound triggered! enabled={}, sound exists={}", levelCompleteEnabled, levelCompleteSound != nullptr);
			if (levelCompleteEnabled) {
				if (levelCompleteSound != nullptr) {
					log::info("Playing custom level-complete sound...");
					FMOD::Channel* channel = nullptr;
					float lvCompVol = Mod::get()->getSettingValue<double>("level-complete-volume");
					log::info("Level-complete volume setting: {}", lvCompVol);
					FMOD_RESULT result = m_system->playSound(levelCompleteSound, nullptr, false, &channel);
					if (result == FMOD_OK && channel) {
						channel->setVolume(lvCompVol * getEffectsVolume());
						log::info("Custom level-complete sound playing successfully!");
						return 1;
					} else {
						log::error("level-complete playSound returned error! Result: {}", static_cast<int>(result));
					}
				} else {
					log::warn("level-complete-enabled but levelCompleteSound is null!");
				}
			} else {
				log::info("Level complete sound disabled");
			}
		}

		return FMODAudioEngine::playEffect(path, speed, p2, volume);
	}
};

class $modify(MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		static bool s_popupHandledThisSession = false;
		auto* mod = Mod::get();

		bool alreadyHandled = s_popupHandledThisSession ||
			(mod->hasSavedValue("not-first-time") && mod->getSavedValue<bool>("not-first-time"));

		if (!alreadyHandled) {
			mod->setSavedValue("not-first-time", true);
			s_popupHandledThisSession = true;

			runFirstTimeV2Migration();

			auto alert = FLAlertLayer::create(
				"Custom Death Sound v2",
				"This is the <cg>v2</c> version of Custom Death Sound. "
				"A lot of internal systems were reworked, including sound effect paths. "
				"Migration has been automated. "
				"To view your sound effects, open mod settings or pause any level and press the <cy>SFX</c> button.",
				"OK"
			);
			alert->m_scene = this;
			alert->show();
		}

		return true;
	}
};
