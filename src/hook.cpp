#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <random>
#include "Utils.hpp"

using namespace geode::prelude;

FMOD::Channel* playingChannel = nullptr;
std::map<std::string, FMOD::Sound*> selectedOnlineSounds;
std::vector<std::string> selectedOnlineSoundPaths;

bool deathSoundEnabled = true;

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

		FMOD::Sound* sound = nullptr;
		if (FMODAudioEngine::sharedEngine()->m_system->createSound(path.string().c_str(), FMOD_DEFAULT, nullptr, &sound) == FMOD_OK) {
			selectedOnlineSounds[path.string()] = sound;
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
				static std::default_random_engine engine{ std::random_device{}() };
				std::uniform_int_distribution<size_t> dist(0, selectedOnlineSounds.size() - 1);

				auto it = selectedOnlineSounds.begin();
				std::advance(it, dist(engine));

				FMOD::Sound* sound = it->second;

				float minPitch = Mod::get()->getSettingValue<double>("pitch-minimum");
				float maxPitch = Mod::get()->getSettingValue<double>("pitch-maximum");
				float pitch = speed;
				if (maxPitch > minPitch) {
					pitch = minPitch + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (maxPitch - minPitch));
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