#include "Utils.hpp"

#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <iterator>
#include <vector>

namespace dsutils {
    namespace {
        constexpr auto kUsedOnlineSfxPathsKey = "used-online-sfx-paths";

        std::filesystem::path metadataPathFor(std::filesystem::path const& soundPath) {
            auto metadataPath = soundPath;
            metadataPath += ".meta.json";
            return metadataPath;
        }

        std::string normalizePathString(std::filesystem::path const& path) {
            std::error_code ec;
            auto absolute = std::filesystem::absolute(path, ec);
            if (ec) {
                return geode::utils::string::pathToString(path.lexically_normal());
            }
            return geode::utils::string::pathToString(absolute.lexically_normal());
        }

        std::string lowerCopy(std::string value) {
            std::transform(value.begin(), value.end(), value.begin(), [](unsigned char ch) {
                return static_cast<char>(std::tolower(ch));
            });
            return value;
        }

        bool isWavPath(std::filesystem::path const& path) {
            return lowerCopy(geode::utils::string::pathToString(path.extension())) == ".wav";
        }

        uint16_t readU16LE(std::vector<uint8_t> const& bytes, size_t offset) {
            return static_cast<uint16_t>(bytes[offset]) |
                   (static_cast<uint16_t>(bytes[offset + 1]) << 8);
        }

        uint32_t readU32LE(std::vector<uint8_t> const& bytes, size_t offset) {
            return static_cast<uint32_t>(bytes[offset]) |
                   (static_cast<uint32_t>(bytes[offset + 1]) << 8) |
                   (static_cast<uint32_t>(bytes[offset + 2]) << 16) |
                   (static_cast<uint32_t>(bytes[offset + 3]) << 24);
        }

        void writeU16LE(std::ofstream& out, uint16_t value) {
            char b[2] = {
                static_cast<char>(value & 0xFF),
                static_cast<char>((value >> 8) & 0xFF),
            };
            out.write(b, 2);
        }

        void writeU32LE(std::ofstream& out, uint32_t value) {
            char b[4] = {
                static_cast<char>(value & 0xFF),
                static_cast<char>((value >> 8) & 0xFF),
                static_cast<char>((value >> 16) & 0xFF),
                static_cast<char>((value >> 24) & 0xFF),
            };
            out.write(b, 4);
        }

        bool convertPcm24WavToPcm16(std::filesystem::path const& inputPath, std::filesystem::path const& outputPath) {
            std::ifstream in(inputPath, std::ios::binary);
            if (!in) {
                return false;
            }

            std::vector<uint8_t> bytes((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
            if (bytes.size() < 44) {
                return false;
            }

            if (std::memcmp(bytes.data(), "RIFF", 4) != 0 || std::memcmp(bytes.data() + 8, "WAVE", 4) != 0) {
                return false;
            }

            size_t fmtOffset = 0;
            uint32_t fmtSize = 0;
            size_t dataOffset = 0;
            uint32_t dataSize = 0;

            for (size_t pos = 12; pos + 8 <= bytes.size();) {
                auto chunkId = reinterpret_cast<char const*>(bytes.data() + pos);
                uint32_t chunkSize = readU32LE(bytes, pos + 4);
                size_t chunkDataPos = pos + 8;
                if (chunkDataPos + chunkSize > bytes.size()) {
                    break;
                }

                if (std::memcmp(chunkId, "fmt ", 4) == 0) {
                    fmtOffset = chunkDataPos;
                    fmtSize = chunkSize;
                } else if (std::memcmp(chunkId, "data", 4) == 0) {
                    dataOffset = chunkDataPos;
                    dataSize = chunkSize;
                }

                pos = chunkDataPos + chunkSize + (chunkSize & 1u);
            }

            if (fmtOffset == 0 || dataOffset == 0 || fmtSize < 16) {
                return false;
            }

            uint16_t audioFormat = readU16LE(bytes, fmtOffset + 0);
            uint16_t channels = readU16LE(bytes, fmtOffset + 2);
            uint32_t sampleRate = readU32LE(bytes, fmtOffset + 4);
            uint16_t bitsPerSample = readU16LE(bytes, fmtOffset + 14);

            if (audioFormat != 1 || bitsPerSample != 24 || channels == 0) {
                return false;
            }

            if (dataSize < 3 || dataOffset + dataSize > bytes.size() || dataSize % 3 != 0) {
                return false;
            }

            uint32_t sampleCount = dataSize / 3;
            uint32_t convertedDataSize = sampleCount * 2;

            std::ofstream out(outputPath, std::ios::binary | std::ios::trunc);
            if (!out) {
                return false;
            }

            out.write("RIFF", 4);
            writeU32LE(out, 36u + convertedDataSize);
            out.write("WAVE", 4);

            out.write("fmt ", 4);
            writeU32LE(out, 16u);
            writeU16LE(out, 1u);
            writeU16LE(out, channels);
            writeU32LE(out, sampleRate);
            writeU32LE(out, sampleRate * channels * 2u);
            writeU16LE(out, static_cast<uint16_t>(channels * 2u));
            writeU16LE(out, 16u);

            out.write("data", 4);
            writeU32LE(out, convertedDataSize);

            for (uint32_t i = 0; i < sampleCount; ++i) {
                size_t src = dataOffset + static_cast<size_t>(i) * 3;
                int32_t sample = static_cast<int32_t>(bytes[src]) |
                                (static_cast<int32_t>(bytes[src + 1]) << 8) |
                                (static_cast<int32_t>(bytes[src + 2]) << 16);
                if (sample & 0x00800000) {
                    sample |= ~0x00FFFFFF;
                }
                int16_t outSample = static_cast<int16_t>(sample >> 8);
                char pcm16[2] = {
                    static_cast<char>(outSample & 0xFF),
                    static_cast<char>((outSample >> 8) & 0xFF),
                };
                out.write(pcm16, 2);
            }

            return static_cast<bool>(out);
        }

        bool ensurePcm16WavFromAnyAudio(
            std::filesystem::path const& originalPath,
            std::filesystem::path const& convertedPath
        ) {
            if (std::filesystem::exists(convertedPath)) {
                return true;
            }

            if (!isWavPath(originalPath)) {
                return false;
            }

            return convertPcm24WavToPcm16(originalPath, convertedPath) && std::filesystem::exists(convertedPath);
        }
    }

    std::string formatDate(int32_t timestamp) {
        using namespace std::chrono;
        auto seconds = static_cast<time_t>(timestamp);
        auto tp = system_clock::from_time_t(seconds);
        return fmt::format("{:%Y-%m-%d}", tp);
    }

    std::filesystem::path getSfxDownloadPath(std::string const& sfxId, std::string const& sfxUrl) {
        auto downloadsDir = Mod::get()->getConfigDir() / "downloaded-sfx";

        std::string filename = sfxId + ".wav";
        if (!sfxUrl.empty()) {
            auto cleanUrl = sfxUrl;
            auto queryPos = cleanUrl.find_first_of("?#");
            if (queryPos != std::string::npos) {
                cleanUrl = cleanUrl.substr(0, queryPos);
            }
            auto slashPos = cleanUrl.find_last_of('/');
            if (slashPos != std::string::npos && slashPos + 1 < cleanUrl.size()) {
                filename = cleanUrl.substr(slashPos + 1);
            }
        }

        auto candidatePath = downloadsDir / filename;
        if (std::filesystem::exists(candidatePath)) {
            return candidatePath;
        }

        auto stem = geode::utils::string::pathToString(std::filesystem::path(filename).stem());
        static constexpr std::array<const char*, 4> extensions = { ".wav", ".mp3", ".ogg", ".flac" };
        for (auto const* ext : extensions) {
            auto altPath = downloadsDir / (stem + ext);
            if (std::filesystem::exists(altPath)) {
                return altPath;
            }
        }

        return downloadsDir / filename;
    }

    std::filesystem::path getSfxPlayablePath(std::string const& sfxId, std::string const& sfxUrl) {
        auto originalPath = getSfxDownloadPath(sfxId, sfxUrl);
        auto convertedPath = originalPath;
        convertedPath += ".16.wav";
        if (std::filesystem::exists(convertedPath)) {
            return convertedPath;
        }
        return originalPath;
    }

    std::filesystem::path ensurePlayableSfxPath(std::filesystem::path const& originalPath) {
        auto convertedPath = originalPath;
        convertedPath += ".16.wav";

        if (ensurePcm16WavFromAnyAudio(originalPath, convertedPath) && std::filesystem::exists(convertedPath)) {
            return convertedPath;
        }

        return originalPath;
    }

    std::filesystem::path getSfxMetadataPath(std::filesystem::path const& soundPath) {
        return metadataPathFor(soundPath);
    }

    DownloadedSfxMetadata getDownloadedSfxMetadata(std::filesystem::path const& soundPath) {
        DownloadedSfxMetadata metadata;
        metadata.id = geode::utils::string::pathToString(soundPath.stem());
        metadata.name = geode::utils::string::pathToString(soundPath.stem());
        metadata.url = std::string("/sounds/") + geode::utils::string::pathToString(soundPath.filename());
        metadata.path = geode::utils::string::pathToString(std::filesystem::absolute(soundPath));

        auto metadataPath = getSfxMetadataPath(soundPath);
        if (!std::filesystem::exists(metadataPath)) {
            return metadata;
        }

        std::ifstream in(metadataPath);
        if (!in) {
            return metadata;
        }

        std::string jsonText((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
        auto parsed = matjson::parse(jsonText);
        if (!parsed.isOk()) {
            return metadata;
        }

        auto value = parsed.unwrap();
        if (value.contains("id")) {
            metadata.id = value["id"].asString().unwrap();
        }
        if (value.contains("name")) {
            metadata.name = value["name"].asString().unwrap();
        }
        if (value.contains("url")) {
            metadata.url = value["url"].asString().unwrapOr(metadata.url);
        }
        if (value.contains("path")) {
            metadata.path = value["path"].asString().unwrap();
        }
        if (value.contains("downloads")) {
            metadata.downloads = value["downloads"].asInt().unwrapOr(0);
        }
        if (value.contains("likes")) {
            metadata.likes = value["likes"].asInt().unwrapOr(0);
        }
        if (value.contains("dislikes")) {
            metadata.dislikes = value["dislikes"].asInt().unwrapOr(0);
        }
        if (value.contains("createdAt")) {
            metadata.createdAt = static_cast<int32_t>(value["createdAt"].asInt().unwrapOr(0));
        }
        if (value.contains("lengthSeconds")) {
            metadata.lengthSeconds = value["lengthSeconds"].asDouble().unwrapOr(-1.0);
        }
        if (value.contains("tags") && value["tags"].isArray()) {
            for (auto const& tagValue : value["tags"]) {
                if (tagValue.isString()) {
                    metadata.tags.push_back(tagValue.asString().unwrapOr(""));
                }
            }
        }

        return metadata;
    }

    void saveDownloadedSfxMetadata(
        std::filesystem::path const& soundPath,
        std::string const& sfxId,
        std::string const& sfxName,
        std::vector<std::string> const& tags,
        matjson::Value const& sfxObject
    ) {
        std::error_code ec;
        std::filesystem::create_directories(soundPath.parent_path(), ec);

        auto metadataPath = getSfxMetadataPath(soundPath);
        matjson::Value value = sfxObject.isObject() ? sfxObject : matjson::Value::object();
        value["id"] = value.contains("id") ? value["id"] : matjson::Value(sfxId);
        value["name"] = value.contains("name") ? value["name"] : matjson::Value(sfxName);
        value["url"] = value.contains("url") ? value["url"] : matjson::Value(std::string("/sounds/") + geode::utils::string::pathToString(soundPath.filename()));
        value["path"] = geode::utils::string::pathToString(std::filesystem::absolute(soundPath));

        if (!value.contains("tags") || !value["tags"].isArray()) {
            value["tags"] = matjson::Value::array();
            for (auto const& tag : tags) {
                value["tags"].push(tag);
            }
        }

        std::ofstream out(metadataPath, std::ios::binary | std::ios::trunc);
        if (!out) {
            log::warn("Failed to write SFX metadata file at {}", geode::utils::string::pathToString(metadataPath));
            return;
        }

        out << value.dump(matjson::NO_INDENTATION);
    }

    void removeDownloadedSfxMetadata(std::filesystem::path const& soundPath) {
        std::error_code ec;
        std::filesystem::remove(getSfxMetadataPath(soundPath), ec);
    }

    std::string makeSfxDownloadUrl(std::string const& sfxUrl) {
        if (sfxUrl.empty()) {
            return "";
        }

        if (sfxUrl.rfind("http://", 0) == 0 || sfxUrl.rfind("https://", 0) == 0) {
            return sfxUrl;
        }

        std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
        if (baseUrl.empty()) {
            return "";
        }

        bool baseHasSlash = !baseUrl.empty() && baseUrl.back() == '/';
        bool pathHasSlash = !sfxUrl.empty() && sfxUrl.front() == '/';

        if (baseHasSlash && pathHasSlash) {
            return baseUrl + sfxUrl.substr(1);
        }
        if (!baseHasSlash && !pathHasSlash) {
            return baseUrl + "/" + sfxUrl;
        }
        return baseUrl + sfxUrl;
    }

    std::vector<std::string> getUsedOnlineSfxPaths() {
        auto paths = Mod::get()->getSavedValue<std::vector<std::string>>(kUsedOnlineSfxPathsKey, {});
        std::sort(paths.begin(), paths.end());
        paths.erase(std::unique(paths.begin(), paths.end()), paths.end());
        return paths;
    }

    void setUsedOnlineSfxPaths(std::vector<std::string> const& paths) {
        auto deduped = paths;
        std::sort(deduped.begin(), deduped.end());
        deduped.erase(std::unique(deduped.begin(), deduped.end()), deduped.end());
        Mod::get()->setSavedValue(kUsedOnlineSfxPathsKey, deduped);
    }

    bool isOnlineSfxPathUsed(std::filesystem::path const& path) {
        auto normalized = normalizePathString(path);
        auto usedPaths = getUsedOnlineSfxPaths();
        return std::find(usedPaths.begin(), usedPaths.end(), normalized) != usedPaths.end();
    }

    void setOnlineSfxPathUsed(std::filesystem::path const& path, bool used) {
        auto normalized = normalizePathString(path);
        auto usedPaths = getUsedOnlineSfxPaths();

        auto it = std::find(usedPaths.begin(), usedPaths.end(), normalized);
        if (used) {
            if (it == usedPaths.end()) {
                usedPaths.push_back(normalized);
            }
        }
        else if (it != usedPaths.end()) {
            usedPaths.erase(it);
        }

        setUsedOnlineSfxPaths(usedPaths);
    }

    bool startPreviewPlayback(
        PreviewPlaybackState& state,
        std::filesystem::path const& originalPath,
        std::string const& sfxName,
        std::string const& sfxId
    ) {
        auto fmod = FMODAudioEngine::sharedEngine();

        if (!std::filesystem::exists(originalPath)) {
            auto absPath = std::filesystem::absolute(originalPath);
            log::warn("File missing for '{}' ({}) at {}:1", sfxName, sfxId, geode::utils::string::pathToString(absPath));
            return false;
        }

        stopPreviewPlayback(state);

        auto soundPath = ensurePlayableSfxPath(originalPath);

        auto absSoundPath = std::filesystem::absolute(soundPath);
        auto soundPathString = geode::utils::string::pathToString(soundPath);
        FMOD_RESULT createResult = fmod->m_system->createSound(soundPathString.c_str(), FMOD_DEFAULT, nullptr, &state.sound);

        if (createResult != FMOD_OK && soundPath != originalPath) {
            state.sound = nullptr;
            soundPath = originalPath;
            absSoundPath = std::filesystem::absolute(soundPath);
            soundPathString = geode::utils::string::pathToString(soundPath);
            createResult = fmod->m_system->createSound(soundPathString.c_str(), FMOD_DEFAULT, nullptr, &state.sound);
        }

        if (createResult != FMOD_OK && soundPath == originalPath) {
            auto convertedPath = originalPath;
            convertedPath += ".16.wav";
            if (ensurePcm16WavFromAnyAudio(originalPath, convertedPath)) {
                log::info("Converted audio for '{}' ({}) -> {}:1", sfxName, sfxId, geode::utils::string::pathToString(std::filesystem::absolute(convertedPath)));
                auto convertedPathString = geode::utils::string::pathToString(convertedPath);
                createResult = fmod->m_system->createSound(convertedPathString.c_str(), FMOD_DEFAULT, nullptr, &state.sound);
                if (createResult == FMOD_OK) {
                    soundPath = convertedPath;
                    absSoundPath = std::filesystem::absolute(soundPath);
                    soundPathString = convertedPathString;
                }
            }
        }

        if (createResult != FMOD_OK) {
            log::error("createSound failed '{}' ({}) result={} path={}:1", sfxName, sfxId, static_cast<int>(createResult), geode::utils::string::pathToString(absSoundPath));
            state.sound = nullptr;
            return false;
        }

        FMOD_RESULT playResult = fmod->m_system->playSound(state.sound, nullptr, false, &state.channel);
        if (playResult != FMOD_OK) {
            log::error("playSound failed '{}' ({}) result={} path={}:1", sfxName, sfxId, static_cast<int>(playResult), geode::utils::string::pathToString(absSoundPath));
            state.sound->release();
            state.sound = nullptr;
            state.channel = nullptr;
            return false;
        }

        state.playing = true;
        log::info("Playing '{}' ({}) from {}:1", sfxName, sfxId, geode::utils::string::pathToString(absSoundPath));
        return true;
    }

    void stopPreviewPlayback(PreviewPlaybackState& state) {
        if (state.channel) {
            state.channel->stop();
            state.channel = nullptr;
        }

        if (state.sound) {
            state.sound->release();
            state.sound = nullptr;
        }

        state.playing = false;
    }
}
