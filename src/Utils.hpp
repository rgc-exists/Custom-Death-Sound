#pragma once

#include <Geode/Geode.hpp>
#include <filesystem>

using namespace geode::prelude;

namespace deathsounds::utils {
    struct DownloadedSfxMetadata {
        std::string id;
        std::string name;
        std::string path;
    };

    struct PreviewPlaybackState {
        FMOD::Sound* sound = nullptr;
        FMOD::Channel* channel = nullptr;
        bool playing = false;
    };

    std::string formatDate(int32_t timestamp);

    std::filesystem::path getSfxDownloadPath(std::string const& sfxId, std::string const& sfxUrl);
    std::filesystem::path getSfxPlayablePath(std::string const& sfxId, std::string const& sfxUrl);
    std::filesystem::path getSfxMetadataPath(std::filesystem::path const& soundPath);
    DownloadedSfxMetadata getDownloadedSfxMetadata(std::filesystem::path const& soundPath);
    void saveDownloadedSfxMetadata(std::filesystem::path const& soundPath, std::string const& sfxId, std::string const& sfxName);
    void removeDownloadedSfxMetadata(std::filesystem::path const& soundPath);
    std::string makeSfxDownloadUrl(std::string const& sfxUrl);

    std::vector<std::string> getUsedOnlineSfxPaths();
    void setUsedOnlineSfxPaths(std::vector<std::string> const& paths);
    bool isOnlineSfxPathUsed(std::filesystem::path const& path);
    void setOnlineSfxPathUsed(std::filesystem::path const& path, bool used);

    bool startPreviewPlayback(
        PreviewPlaybackState& state,
        std::filesystem::path const& originalPath,
        std::string const& sfxName,
        std::string const& sfxId
    );
    void stopPreviewPlayback(PreviewPlaybackState& state);
}