#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <chrono>
#include <cstdlib>
#include <random>
#include "Utils.hpp"

using namespace geode::prelude;

FMOD::Channel* playingChannel = nullptr;
std::map<std::string, FMOD::Sound*> selectedOnlineSounds;
std::vector<std::string> selectedOnlineSoundPaths;

bool deathSoundEnabled = true;
std::mt19937 soundRng;

std::filesystem::path transcodeLoadedSoundIfNeeded(std::filesystem::path const& originalPath) {
	auto convertedPath = originalPath;
	convertedPath += ".16.wav";

	if (std::filesystem::exists(convertedPath)) {
		return convertedPath;
	}

	std::error_code ec;
	std::filesystem::remove(convertedPath, ec);

#ifdef _WIN32
	auto command = std::string("ffmpeg -y -hide_banner -loglevel error -i \"") + originalPath.string() +
		"\" -acodec pcm_s16le \"" + convertedPath.string() + "\" >nul 2>&1";
#else
	auto command = std::string("ffmpeg -y -hide_banner -loglevel error -i \"") + originalPath.string() +
		"\" -acodec pcm_s16le \"" + convertedPath.string() + "\" >/dev/null 2>&1";
#endif

	if (std::system(command.c_str()) == 0 && std::filesystem::exists(convertedPath)) {
		return convertedPath;
	}

	return originalPath;
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

	listenForSettingChanges<bool>("death-sound-enabled", [](bool value) {
		deathSoundEnabled = value;
		reloadSounds();
	});
}

class $modify(FMODAudioEngine) {
	int playEffect(gd::string path, float speed, float p2, float volume) {
		if (path == "explode_11.ogg") {
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

				FMOD_RESULT result = m_system->playSound(sound, nullptr, false, &playingChannel);
				if (result == FMOD_OK && playingChannel) {
					playingChannel->setVolume(customVolume * getEffectsVolume());
					playingChannel->setPitch(pitch);
				} else {
					log::error("playSound returned error!");
				}

				return 1;
			}
		}

		return FMODAudioEngine::playEffect(path, speed, p2, volume);
	}
};