#include <Geode/Geode.hpp>
#include <Geode/utils/file.hpp>>
#include <Geode/modify/FMODAudioEngine.hpp>
#include <Geode/modify/MenuLayer.hpp>

#include <fstream>
#include <iostream>
#include <filesystem>
#include <map>

using namespace geode::prelude;


static FMOD::Sound* death_sound;
static std::string death_sound_path;

static FMOD::Channel* playing_channel; //Only gets set when clear-on-reset setting is false!

static std::map<std::string, FMOD::Sound*> extraDeathSounds;
static bool extra_sounds_enabled = false;
static bool clear_on_reset = true;

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
				std::string path_str = p.path().string();
				if (FMODAudioEngine::sharedEngine()->m_system->createSound(path_str.c_str(), FMOD_DEFAULT, nullptr, &sound) == FMOD_OK) {
					extraDeathSounds[path_str] = sound;
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
	
	if (death_sound != nullptr) {
		death_sound->release();
	}

	log::info("Reloading death sound(s)");
	if (extra_sounds_enabled) {
		reloadExtraSounds();
	}
	else {
		std::filesystem::path path = getDeathSoundPath();
		if (std::filesystem::exists(path)) {
			FMOD::Sound* sound;
			std::string path_str = path.string();
			if (FMODAudioEngine::sharedEngine()->m_system->createSound(path_str.c_str(), FMOD_DEFAULT, nullptr, &sound) == FMOD_OK) {
				death_sound = sound;
				death_sound_path = path.string();
			}
		}
		else {
			log::warn("Death sound path doesn't exist!");
		}
	}
}

$execute{
	extra_sounds_enabled = Mod::get()->getSettingValue<bool>("extra-sounds-enabled");
	clear_on_reset = Mod::get()->getSettingValue<bool>("clear-on-reset");

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
		extra_sounds_enabled = value;
		reloadSounds();
	});
	listenForSettingChanges("clear-on-reset", [](bool value) {
		clear_on_reset = value;
		});

}



class $modify(FMODAudioEngine) {
	void playEffect(gd::string path, float speed, float p2, float volume) {

		FMOD::Sound* sound;
		if (path == "explode_11.ogg") {


			if (extra_sounds_enabled && extraDeathSounds.size() > 0) {

				auto it = extraDeathSounds.begin();
				std::advance(it, rand() % extraDeathSounds.size());
				path = it->first;
				sound = extraDeathSounds[path];
			}
			else if (death_sound != nullptr) {
				path = death_sound_path;
				sound = death_sound;
			} else {
				FMODAudioEngine::playEffect(path, speed, p2, volume);
				return;
			}

			float min_pitch = Mod::get()->getSettingValue<double>("pitch-minimum");
			float max_pitch = Mod::get()->getSettingValue<double>("pitch-maximum");
			if (min_pitch >= max_pitch) min_pitch = max_pitch;
			speed = min_pitch + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max_pitch - min_pitch)));

			volume = Mod::get()->getSettingValue<double>("volume");

			if (!clear_on_reset) {

				FMOD_RESULT result = m_system->playSound(
					sound,
					nullptr,
					false,
					&playing_channel
				);
				if (result == FMOD_OK) {
					playing_channel->setVolume(volume);
					playing_channel->setPitch(speed);
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