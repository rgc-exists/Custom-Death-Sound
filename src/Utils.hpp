#pragma once

#include <Geode/Geode.hpp>
#include <filesystem>

using namespace geode::prelude;

namespace deathsounds::utils {
    struct PreviewPlaybackState {
        FMOD::Sound* sound = nullptr;
        FMOD::Channel* channel = nullptr;
        bool playing = false;
    };

    std::string formatDate(int32_t timestamp);

    std::filesystem::path getSfxDownloadPath(std::string const& sfxId, std::string const& sfxUrl);
    std::filesystem::path getSfxPlayablePath(std::string const& sfxId, std::string const& sfxUrl);
    std::string makeSfxDownloadUrl(std::string const& sfxUrl);

    bool startPreviewPlayback(
        PreviewPlaybackState& state,
        std::filesystem::path const& originalPath,
        std::string const& sfxName,
        std::string const& sfxId
    );
    void stopPreviewPlayback(PreviewPlaybackState& state);
}