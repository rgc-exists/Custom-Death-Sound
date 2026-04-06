#pragma once

#include <Geode/Geode.hpp>
#include <filesystem>
#include <vector>

using namespace geode::prelude;

namespace deathsounds::utils {
    struct DownloadedSfxMetadata {
        std::string id;
        std::string name;
        std::string url;
        std::string path;
        int downloads = 0;
        int likes = 0;
        int dislikes = 0;
        int32_t createdAt = 0;
        double lengthSeconds = -1.0;
        std::vector<std::string> tags;
    };

    struct PreviewPlaybackState {
        FMOD::Sound* sound = nullptr;
        FMOD::Channel* channel = nullptr;
        bool playing = false;
    };

    std::string formatDate(int32_t timestamp);

    std::filesystem::path getSfxDownloadPath(std::string const& sfxId, std::string const& sfxUrl);
    std::filesystem::path getSfxPlayablePath(std::string const& sfxId, std::string const& sfxUrl);
    std::filesystem::path ensurePlayableSfxPath(std::filesystem::path const& originalPath);
    std::filesystem::path getSfxMetadataPath(std::filesystem::path const& soundPath);
    DownloadedSfxMetadata getDownloadedSfxMetadata(std::filesystem::path const& soundPath);
    void saveDownloadedSfxMetadata(
        std::filesystem::path const& soundPath,
        std::string const& sfxId,
        std::string const& sfxName,
        std::vector<std::string> const& tags = {},
        matjson::Value const& sfxObject = matjson::Value()
    );
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