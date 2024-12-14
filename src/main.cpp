#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <Geode/modify/MenuLayer.hpp>

#include <fstream>
#include <iostream>
#include <filesystem>
#include <map>

using namespace geode::prelude;


static FMOD::Sound* deathSound;
static std::string deathSoundPath;

static FMOD::Channel* playingChannel; //Only gets set when clear-on-reset setting is false!

static std::map<std::string, FMOD::Sound*> extraDeathSounds;
static bool extraSoundsEnabled = false;
static bool clearOnReset = true;

std::filesystem::path getDeathSoundPath() {
	return Mod::get()->getSettingValue<std::filesystem::path>("sound-path");
}
std::filesystem::path getExtraDeathSoundsPath() {
	return Mod::get()->getSettingValue<std::filesystem::path>("extra-sounds-path");
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

	log::info("Reloading death sound(s)");
	if (extraSoundsEnabled) {
		reloadExtraSounds();
	}
	else {
		std::filesystem::path path = getDeathSoundPath();
		if (std::filesystem::exists(path)) {
			FMOD::Sound* sound;
			std::string pathStr = path.string();
			if (FMODAudioEngine::sharedEngine()->m_system->createSound(pathStr.c_str(), FMOD_DEFAULT, nullptr, &sound) == FMOD_OK) {
				deathSound = sound;
				deathSoundPath = path.string();
			}
		}
		else {
			log::warn("Death sound path doesn't exist!");
		}
	}
}

$execute{
	extraSoundsEnabled = Mod::get()->getSettingValue<bool>("extra-sounds-enabled");
	clearOnReset = Mod::get()->getSettingValue<bool>("clear-on-reset");

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
	listenForSettingChanges("clear-on-reset", [](bool value) {
		extraSoundsEnabled = value;
		});

}



class $modify(FMODAudioEngine) {
	void playEffect(gd::string path, float speed, float p2, float volume) {

		FMOD::Sound* sound;
		if (path == "explode_11.ogg") {


			if (extraSoundsEnabled && extraDeathSounds.size() > 0) {

				auto it = extraDeathSounds.begin();
				std::advance(it, rand() % extraDeathSounds.size());
				path = it->first;
				sound = extraDeathSounds[path];
			}
			else if (deathSound != nullptr) {
				path = deathSoundPath;
				sound = deathSound;
			} else {
				FMODAudioEngine::playEffect(path, speed, p2, volume);
				return;
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
					playingChannel->setVolume(volume);
					playingChannel->setPitch(speed);
				}
				else {
					log::error("m_system->playSound returned error!");
				}
				return;
			}
		}

		FMODAudioEngine::playEffect(path, speed, p2, volume);
	}
};