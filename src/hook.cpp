#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "Utils.hpp"

using namespace geode::prelude;

std::map<std::string, FMOD::Sound*> selectedOnlineSounds;
std::vector<std::string> selectedOnlineSoundPaths;

bool deathSoundEnabled = true;

void reloadSelectedOnlineSounds() {
	for (auto& [_, sound] : selectedOnlineSounds) {
		sound->release();
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
		sound->release();
	}
	selectedOnlineSounds.clear();

	log::info("Reloading death sound(s)");
	reloadSelectedOnlineSounds();
}

$execute{
	deathSoundEnabled = Mod::get()->getSettingValue<bool>("death-sound-enabled");

	reloadSounds();


	listenForSettingChanges<bool>("death-sound-enabled", [](bool value) {
		deathSoundEnabled = value;
		reloadSounds();
		});
}

class $modify(FMODAudioEngine) {
	int playEffect(gd::string path, float speed, float p2, float volume) {
		refreshSelectedOnlineSoundsIfNeeded();

		if (path == "explode_11.ogg") {
			if (deathSoundEnabled) {
				if (selectedOnlineSounds.size() > 0) {
					auto it = selectedOnlineSounds.begin();
					std::advance(it, rand() % selectedOnlineSounds.size());
					path = it->first;
				} else {
					FMODAudioEngine::playEffect(path, speed, p2, volume);
					return 1;
				}

				float minPitch = Mod::get()->getSettingValue<double>("pitch-minimum");
				float maxPitch = Mod::get()->getSettingValue<double>("pitch-maximum");
				if (maxPitch <= minPitch) {
					speed = minPitch;
				} else {
					speed = minPitch + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (maxPitch - minPitch));
				}

				volume = Mod::get()->getSettingValue<double>("volume");
			}
		}

		return FMODAudioEngine::playEffect(path, speed, p2, volume);
	}
};