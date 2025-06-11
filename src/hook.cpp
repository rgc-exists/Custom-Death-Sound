#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

FMOD::Sound* deathSound;
std::string deathSoundPath;
FMOD::Sound* levelCompleteSound;
std::string levelCompleteSoundPath;

FMOD::Channel* playingChannel; //Only gets set when clear-on-reset setting is false!

std::map<std::string, FMOD::Sound*> extraDeathSounds;

bool extraSoundsEnabled = false;
bool deathSoundEnabled = true;
bool muteDeathSound = false;

bool levelCompleteEnabled = false;
bool muteLevelComplete = false;

bool clearOnReset = true;

std::filesystem::path getDeathSoundPath() {
	return Mod::get()->getSettingValue<std::filesystem::path>("sound-path");
}
std::filesystem::path getExtraDeathSoundsPath() {
	return Mod::get()->getSettingValue<std::filesystem::path>("extra-sounds-path");
}
std::filesystem::path getLevelCompletePath() {
	return Mod::get()->getSettingValue<std::filesystem::path>("level-complete-path");
}

void reloadExtraSounds() {
	std::filesystem::path path = getExtraDeathSoundsPath();
	if (std::filesystem::exists(path)) {
		std::vector<std::string> exts = { ".ogg", ".wav", ".mp3", ".flac" };
		for (auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			if (std::find(exts.begin(), exts.end(), p.path().extension()) != exts.end()) {
				FMOD::Sound* sound;
				std::string pathStr = p.path().string();
				if (FMODAudioEngine::sharedEngine()->m_system->createSound(pathStr.c_str(), FMOD_DEFAULT, nullptr, &sound) == FMOD_OK) {
					extraDeathSounds[pathStr] = sound;
				}
			}
		}
	}
	else {
		log::warn("Extra death sounds directory doesn't exist!");
	}
}

void reloadSounds() {

	for (std::map<std::string, FMOD::Sound*>::iterator itr = extraDeathSounds.begin(); itr != extraDeathSounds.end(); ++itr) {
		itr->second->release();
	}
	extraDeathSounds.clear();
	
	if (deathSound != nullptr) {
		deathSound->release();
	}
	if (levelCompleteSound != nullptr) {
		levelCompleteSound->release();
	}

	log::info("Reloading death sound(s)");
	if (extraSoundsEnabled) {
		reloadExtraSounds();
	}
	else {
		if (deathSoundEnabled) {
			std::filesystem::path path = getDeathSoundPath();
			if (std::filesystem::exists(path)) {
				FMOD::Sound* sound;
				std::string pathStr = path.string();
				if (FMODAudioEngine::sharedEngine()->m_system->createSound(pathStr.c_str(), FMOD_DEFAULT, nullptr, &sound) == FMOD_OK) {
					deathSound = sound;
					deathSoundPath = path.string();
				}
			} else {
				log::warn("Death sound path doesn't exist!");
			}
		}
	}

	if (levelCompleteEnabled) {
		std::filesystem::path path = getLevelCompletePath();
		if (std::filesystem::exists(path)) {
			FMOD::Sound* sound;
			std::string pathStr = path.string();
			if (FMODAudioEngine::sharedEngine()->m_system->createSound(pathStr.c_str(), FMOD_DEFAULT, nullptr, &sound) == FMOD_OK) {
				levelCompleteSound = sound;
				levelCompleteSoundPath = path.string();
			}
		} else {
			log::warn("Level complete sound path doesn't exist!");
		}
	}
}

$execute{
	extraSoundsEnabled = Mod::get()->getSettingValue<bool>("extra-sounds-enabled");
	clearOnReset = Mod::get()->getSettingValue<bool>("clear-on-reset");
	deathSoundEnabled = Mod::get()->getSettingValue<bool>("death-sound-enabled");
	levelCompleteEnabled = Mod::get()->getSettingValue<bool>("level-complete-enabled");
	muteDeathSound = Mod::get()->getSettingValue<bool>("mute-death-sound");
	muteLevelComplete = Mod::get()->getSettingValue<bool>("mute-level-complete");

	std::filesystem::path defaultPath = Mod::get()->getConfigDir() / "extraDeathSounds";
	if (!std::filesystem::exists(Mod::get()->getConfigDir())) {
		std::filesystem::create_directory(Mod::get()->getConfigDir());
	}
	if (!std::filesystem::exists(defaultPath)) {
		log::info("Default extra death sounds directory does not exist. Creating...");
		std::filesystem::create_directory(defaultPath);
	}

	reloadSounds();


	listenForSettingChanges("sound-path", [](std::filesystem::path value) {
		reloadSounds();
		});
	listenForSettingChanges("extra-sounds-path", [](std::filesystem::path value) {
		reloadSounds();
		});
	listenForSettingChanges("extra-sounds-enabled", [](bool value) {
		extraSoundsEnabled = value;
		reloadSounds();
		});
	listenForSettingChanges("death-sound-enabled", [](bool value) {
		deathSoundEnabled = value;
		reloadSounds();
		});
	listenForSettingChanges("level-complete-path", [](std::filesystem::path value) {
		reloadSounds();
		});
	listenForSettingChanges("level-complete-enabled", [](bool value) {
		levelCompleteEnabled = value;
		reloadSounds();
		});
	listenForSettingChanges("clear-on-reset", [](bool value) {
		clearOnReset = value;
		});
	listenForSettingChanges("mute-death-sound", [](bool value) {
		muteDeathSound = value;
		});
	listenForSettingChanges("mute-level-complete", [](bool value) {
		muteLevelComplete = value;
		});
}

class $modify(FMODAudioEngine) {
	int playEffect(gd::string path, float speed, float p2, float volume) {

		FMOD::Sound* sound;
		if (path == "explode_11.ogg") {
			if (muteDeathSound)
				return 1;

			if (deathSoundEnabled) {
				if (extraSoundsEnabled && extraDeathSounds.size() > 0) {
					auto it = extraDeathSounds.begin();
					std::advance(it, rand() % extraDeathSounds.size());
					path = it->first;
					sound = extraDeathSounds[path];
				} else if (deathSound != nullptr) {
					path = deathSoundPath;
					sound = deathSound;
				} else {
					FMODAudioEngine::playEffect(path, speed, p2, volume);
					return 1;
				}

				float minPitch = Mod::get()->getSettingValue<double>("pitch-minimum");
				float maxPitch = Mod::get()->getSettingValue<double>("pitch-maximum");
				if (minPitch >= maxPitch) minPitch = maxPitch;
				speed = minPitch + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (maxPitch - minPitch)));

				volume = Mod::get()->getSettingValue<double>("volume");

				if (!clearOnReset) {
					FMOD_RESULT result = m_system->playSound(
						sound,
						nullptr,
						false,
						&playingChannel
					);
					if (result == FMOD_OK) {
						playingChannel->setVolume(volume * getEffectsVolume());
						playingChannel->setPitch(speed);
					}
					else {
						log::error("m_system->playSound returned error!");
					}
					return 1;
				}
			}
		} else if (path == "endStart_02.ogg") {
			if (muteLevelComplete)
				return 1;

			if (levelCompleteEnabled) {
				if (levelCompleteSound != nullptr) {
					path = levelCompleteSoundPath;
				}
				else {
					FMODAudioEngine::playEffect(path, speed, p2, volume);
					return 1;
				}
				volume = Mod::get()->getSettingValue<double>("level-complete-volume");
			}
		}

		return FMODAudioEngine::playEffect(path, speed, p2, volume);
	}
};