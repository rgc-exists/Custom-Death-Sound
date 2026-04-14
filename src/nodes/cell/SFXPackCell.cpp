#include "SFXPackCell.hpp"
#include "../../Requests.hpp"
#include <Geode/ui/Notification.hpp>
#include <Geode/utils/web.hpp>

namespace {
    constexpr auto kEnabledPackIdsKey = "enabled-online-pack-ids";
    constexpr auto kDownloadedPackIdsKey = "downloaded-online-pack-ids";

    std::string packSoundsKey(std::string const& packId) {
        return fmt::format("enabled-online-pack-sounds-{}", packId);
    }

    std::string downloadedPackSoundsKey(std::string const& packId) {
        return fmt::format("downloaded-online-pack-sounds-{}", packId);
    }

    std::vector<std::string> getEnabledPackIds() {
        auto ids = Mod::get()->getSavedValue<std::vector<std::string>>(kEnabledPackIdsKey, {});
        std::sort(ids.begin(), ids.end());
        ids.erase(std::unique(ids.begin(), ids.end()), ids.end());
        return ids;
    }

    void setEnabledPackIds(std::vector<std::string> const& ids) {
        auto deduped = ids;
        std::sort(deduped.begin(), deduped.end());
        deduped.erase(std::unique(deduped.begin(), deduped.end()), deduped.end());
        Mod::get()->setSavedValue(kEnabledPackIdsKey, deduped);
    }

    std::vector<std::string> getDownloadedPackIds() {
        auto ids = Mod::get()->getSavedValue<std::vector<std::string>>(kDownloadedPackIdsKey, {});
        std::sort(ids.begin(), ids.end());
        ids.erase(std::unique(ids.begin(), ids.end()), ids.end());
        return ids;
    }

    void setDownloadedPackIds(std::vector<std::string> const& ids) {
        auto deduped = ids;
        std::sort(deduped.begin(), deduped.end());
        deduped.erase(std::unique(deduped.begin(), deduped.end()), deduped.end());
        Mod::get()->setSavedValue(kDownloadedPackIdsKey, deduped);
    }

    void registerPackUsage(std::string const& packId, std::vector<std::string> const& soundIds) {
        auto ids = getEnabledPackIds();
        if (std::find(ids.begin(), ids.end(), packId) == ids.end()) {
            ids.push_back(packId);
            setEnabledPackIds(ids);
        }

        std::vector<std::string> storedSounds;
        storedSounds.reserve(soundIds.size());
        for (auto const& soundId : soundIds) {
            storedSounds.push_back(static_cast<std::string>(soundId));
        }
        Mod::get()->setSavedValue(packSoundsKey(packId), storedSounds);
    }

    std::unordered_set<std::string> collectOtherEnabledPackSounds(std::string const& excludedPackId) {
        std::unordered_set<std::string> sounds;
        for (auto const& packId : getEnabledPackIds()) {
            if (packId == excludedPackId) {
                continue;
            }

            auto ids = Mod::get()->getSavedValue<std::vector<std::string>>(packSoundsKey(packId), {});
            for (auto const& soundId : ids) {
                sounds.insert(soundId);
            }
        }
        return sounds;
    }

    void unregisterPackUsage(std::string const& packId) {
        auto ids = getEnabledPackIds();
        ids.erase(std::remove(ids.begin(), ids.end(), packId), ids.end());
        setEnabledPackIds(ids);
        Mod::get()->setSavedValue(packSoundsKey(packId), std::vector<std::string>{});
    }

    std::vector<std::string> toStdSoundIds(std::vector<std::string> const& soundIds) {
        std::vector<std::string> ids;
        ids.reserve(soundIds.size());
        for (auto const& soundId : soundIds) {
            ids.push_back(static_cast<std::string>(soundId));
        }
        std::sort(ids.begin(), ids.end());
        ids.erase(std::unique(ids.begin(), ids.end()), ids.end());
        return ids;
    }

    void registerDownloadedPackMetadata(std::string const& packId, std::vector<std::string> const& soundIds) {
        auto ids = getDownloadedPackIds();
        if (std::find(ids.begin(), ids.end(), packId) == ids.end()) {
            ids.push_back(packId);
            setDownloadedPackIds(ids);
        }

        Mod::get()->setSavedValue(downloadedPackSoundsKey(packId), toStdSoundIds(soundIds));
    }

    void removeDownloadedPackMetadata(std::string const& packId) {
        auto ids = getDownloadedPackIds();
        ids.erase(std::remove(ids.begin(), ids.end(), packId), ids.end());
        setDownloadedPackIds(ids);
        Mod::get()->setSavedValue(downloadedPackSoundsKey(packId), std::vector<std::string>{});
    }

    std::vector<std::string> getDownloadedPackSoundIds(std::string const& packId) {
        std::vector<std::string> ids;
        auto stored = Mod::get()->getSavedValue<std::vector<std::string>>(downloadedPackSoundsKey(packId), {});
        ids.reserve(stored.size());
        for (auto const& soundId : stored) {
            ids.push_back(soundId);
        }
        return ids;
    }

    matjson::Value extractSfxObject(matjson::Value const& payload) {
        if (!payload.isObject()) {
            return matjson::Value();
        }

        if (payload.contains("sfx") && payload["sfx"].isObject()) {
            return payload["sfx"];
        }

        if (payload.contains("data")) {
            auto const& data = payload["data"];
            if (data.isObject()) {
                if (data.contains("sfx") && data["sfx"].isObject()) {
                    return data["sfx"];
                }
                return data;
            }
        }

        return payload;
    }

    std::string getStringField(matjson::Value const& object, std::initializer_list<const char*> keys, std::string const& fallback = {}) {
        if (!object.isObject()) {
            return fallback;
        }

        for (auto const* key : keys) {
            if (!object.contains(key)) {
                continue;
            }

            auto value = object[key].asString();
            if (!value) {
                continue;
            }

            auto result = value.unwrapOr("");
            if (!result.empty()) {
                return result;
            }
        }

        return fallback;
    }

    bool startsWith(std::string const& value, std::string_view prefix) {
        return value.size() >= prefix.size() && std::equal(prefix.begin(), prefix.end(), value.begin());
    }

    std::string normalizeDownloadCandidate(std::string value, std::string const& soundId) {
        if (value.empty()) {
            return {};
        }

        if (startsWith(value, "http://") || startsWith(value, "https://")) {
            return value;
        }

        if (value == soundId) {
            return std::string("/sounds/") + soundId + ".wav";
        }

        if (value.front() == '/') {
            return value;
        }

        if (value.find('/') == std::string::npos) {
            return std::string("/sounds/") + value;
        }

        return std::string("/") + value;
    }

    void appendCandidate(std::vector<std::string>& out, std::string const& candidate) {
        if (candidate.empty()) {
            return;
        }

        if (std::find(out.begin(), out.end(), candidate) == out.end()) {
            out.push_back(candidate);
        }
    }

    std::string describeCandidates(std::vector<std::string> const& candidates) {
        if (candidates.empty()) {
            return "[]";
        }

        std::string result = "[";
        for (size_t i = 0; i < candidates.size(); ++i) {
            if (i > 0) {
                result += ", ";
            }
            result += candidates[i];
        }
        result += "]";
        return result;
    }
}

namespace deathsounds {
    bool SFXPackCell::init(int index, std::string id, std::string name, std::vector<std::string> soundIds, int downloads, int32_t createdAt) {
        if (!SFXCell::init(index, id, name, makeSoundRelativeUrl(id), downloads, createdAt, true, false, {}, false)) {
            return false;
        }

        m_soundIds = std::move(soundIds);
        m_trackCount = static_cast<int>(m_soundIds.size());
        m_serverDownloads = downloads;
        recomputePackStateFromSounds();
        refreshActionButtons();

        CCLayer* widget = nullptr;
        if (auto children = this->getChildren()) {
            for (unsigned int i = 0; i < children->count(); ++i) {
                auto layer = typeinfo_cast<CCLayer*>(children->objectAtIndex(i));
                if (!layer) {
                    continue;
                }

                if (layer->getContentWidth() < this->getContentWidth()) {
                    widget = layer;
                    break;
                }
            }
        }

        if (!widget) {
            return true;
        }

        auto downloadsSprite = CCSprite::createWithSpriteFrameName("GJ_sDownloadIcon_001.png");
        downloadsSprite->setPosition({ 20.f, 20.f });
        widget->addChild(downloadsSprite);

        this->m_downloadsText = CCLabelBMFont::create(formatCountCompact(m_serverDownloads).c_str(), "bigFont.fnt");
        this->m_downloadsText->setAnchorPoint({ 0.f, 0.5f });
        this->m_downloadsText->setScale(0.4f);
        this->m_downloadsText->setPosition({ 30.f, 20.f });
        widget->addChild(this->m_downloadsText);

        auto tracksSprite = CCSprite::createWithSpriteFrameName("GJ_musicIcon_001.png");
        tracksSprite->setPosition({ 95.f, 20.f });
        tracksSprite->setScale(0.75f);
        widget->addChild(tracksSprite);

        auto tracksText = CCLabelBMFont::create(formatCountCompact(m_trackCount).c_str(), "bigFont.fnt");
        tracksText->setAnchorPoint({ 0.f, 0.5f });
        tracksText->setScale(0.4f);
        tracksText->setPosition({ 105.f, 20.f });
        widget->addChild(tracksText);

        return true;
    }

    SFXPackCell* SFXPackCell::create(int index, std::string id, std::string name, std::vector<std::string> soundIds, int downloads, int32_t createdAt) {
        auto ret = new SFXPackCell();
        if (ret && ret->init(index, std::move(id), std::move(name), std::move(soundIds), downloads, createdAt)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }

    std::string SFXPackCell::makeSoundRelativeUrl(std::string const& soundId) {
        return std::string("/sounds/") + std::string(soundId) + ".wav";
    }

    std::string SFXPackCell::formatCountCompact(int value) {
        char buf[16];
        if (value >= 1000000000)
            std::snprintf(buf, sizeof(buf), "%.1fB", value / 1000000000.0);
        else if (value >= 1000000)
            std::snprintf(buf, sizeof(buf), "%.1fM", value / 1000000.0);
        else if (value >= 1000)
            std::snprintf(buf, sizeof(buf), "%.1fK", value / 1000.0);
        else
            std::snprintf(buf, sizeof(buf), "%d", value);

        std::string s(buf);
        if (s.find('.') != std::string::npos) {
            s.erase(s.find_last_not_of('0') + 1, std::string::npos);
            if (!s.empty() && s.back() == '.') s.pop_back();
        }
        return s;
    }

    std::filesystem::path SFXPackCell::resolveSoundPath(std::string const& soundId) const {
        auto fallback = utils::getSfxDownloadPath(soundId, makeSoundRelativeUrl(soundId));
        if (std::filesystem::exists(fallback)) {
            return fallback;
        }

        auto downloadDir = Mod::get()->getConfigDir() / "downloaded-sfx";
        if (!std::filesystem::exists(downloadDir)) {
            return fallback;
        }

        for (const auto& entry : std::filesystem::directory_iterator(downloadDir)) {
            if (!entry.is_regular_file()) {
                continue;
            }

            auto path = entry.path();
                auto ext = geode::utils::string::pathToString(path.extension());
            if (ext != ".wav" && ext != ".ogg" && ext != ".mp3") {
                continue;
            }

                if (geode::utils::string::pathToString(path.filename()).ends_with(".16.wav")) {
                continue;
            }

            auto metadata = utils::getDownloadedSfxMetadata(path);
            if (metadata.id == soundId) {
                return path;
            }
        }

        return fallback;
    }

    void SFXPackCell::validateDownloadState() {
        if (m_downloadState != DownloadState::Downloaded) {
            return;
        }

        log::info("[Pack Download] Validating downloaded pack '{}' ({})", m_name, m_sfxId);
        for (auto const& soundId : m_soundIds) {
            auto path = resolveSoundPath(soundId);
            if (!std::filesystem::exists(path)) {
                log::warn(
                    "[Pack Download] Missing sound '{}' in pack '{}' ({}) at {}",
                    soundId,
                    m_name,
                    m_sfxId,
                    geode::utils::string::pathToString(path)
                );
                if (m_inUse) {
                    disablePackSoundsRespectingOtherPacks();
                }
                m_downloadState = DownloadState::NotDownloaded;
                m_inUse = false;
                refreshActionButtons();
                return;
            }
        }
    }

    void SFXPackCell::recomputePackStateFromSounds(bool forceStateUpdate) {
        if (m_soundIds.empty()) {
            m_inUse = false;
            m_downloadState = DownloadState::NotDownloaded;
            return;
        }

        bool allEnabled = true;
        int foundDownloaded = 0;

        for (auto const& soundId : m_soundIds) {
            auto path = resolveSoundPath(soundId);
            if (std::filesystem::exists(path)) {
                ++foundDownloaded;
            } else {
                log::info(
                    "[Pack Download] Missing file while recomputing pack '{}' ({}) sound '{}' -> {}",
                    m_name,
                    m_sfxId,
                    soundId,
                    geode::utils::string::pathToString(path)
                );
            }

            if (!utils::isOnlineSfxPathUsed(path)) {
                allEnabled = false;
            }
        }

        m_inUse = allEnabled;
        if (forceStateUpdate || m_downloadState != DownloadState::Downloading) {
            m_downloadState = (foundDownloaded == static_cast<int>(m_soundIds.size()))
                ? DownloadState::Downloaded
                : DownloadState::NotDownloaded;
        }
    }

    void SFXPackCell::notifyProgress(std::string const& message, NotificationIcon icon, float time) {
        if (auto notif = Notification::create(message, icon, time)) {
            notif->show();
        }
    }

    void SFXPackCell::onDownloadToggle(CCObject* sender) {
        this->unschedule(schedule_selector(SFXPackCell::refreshActionButtonsDeferred));
        this->schedule(schedule_selector(SFXPackCell::refreshActionButtonsDeferred), 0.f);

        log::info(
            "[Pack Download] Toggle pressed for '{}' ({}) state={} downloaded={} skipped={} failed={}",
            m_name,
            m_sfxId,
            static_cast<int>(m_downloadState),
            m_downloadedCount,
            m_skippedCount,
            m_failedCount
        );

        if (m_downloadState == DownloadState::Downloaded) {
            refreshActionButtons();
            return;
        }
        
        if (m_downloadState == DownloadState::NotDownloaded) {
            startPackDownload();
            return;
        }

        if (m_downloadState == DownloadState::Downloading) {
            cancelPackDownload();
            return;
        }

        refreshActionButtons();
    }

    void SFXPackCell::onExit() {
        log::info("[Pack Download] Exiting '{}' ({}) and cancelling in-flight tasks", m_name, m_sfxId);
        m_cancelRequested = true;
        m_sfxInfoTask.cancel();
        m_packDownloadTask.cancel();
        SFXCell::onExit();
    }

    void SFXPackCell::startPackDownload() {
        if (m_soundIds.empty()) {
            notifyProgress("Pack has no sounds to download.", NotificationIcon::Warning, 1.0f);
            refreshActionButtons();
            return;
        }

        log::info(
            "[Pack Download] Starting pack '{}' ({}) with {} sounds",
            m_name,
            m_sfxId,
            m_soundIds.size()
        );

        m_preDownloadState = m_downloadState;
        m_preDownloadInUse = m_inUse;
        m_cancelRequested = false;
        m_downloadIndex = 0;
        m_downloadedCount = 0;
        m_skippedCount = 0;
        m_failedCount = 0;
        m_downloadState = DownloadState::Downloading;
        refreshActionButtons();

        notifyProgress(fmt::format("Downloading {} sounds...", m_soundIds.size()), NotificationIcon::Loading, 0.8f);
        downloadNextSound();
    }

    void SFXPackCell::refreshActionButtonsDeferred(float) {
        this->unschedule(schedule_selector(SFXPackCell::refreshActionButtonsDeferred));
        refreshActionButtons();
    }

    void SFXPackCell::cancelPackDownload() {
        log::info("[Pack Download] Cancel requested for '{}' ({})", m_name, m_sfxId);
        m_cancelRequested = true;
        m_sfxInfoTask.cancel();
        m_packDownloadTask.cancel();
        m_downloadState = m_preDownloadState;
        m_inUse = m_preDownloadInUse;
        refreshActionButtons();
        notifyProgress("Pack download cancelled.", NotificationIcon::Warning, 0.8f);
    }

    void SFXPackCell::startSoundDownload(std::string const& soundId, std::string const& displayName, std::vector<std::string> candidates) {
        appendCandidate(candidates, makeSoundRelativeUrl(soundId));

        log::info(
            "[Pack Download] Preparing sound '{}' ({}) with candidates {}",
            displayName,
            soundId,
            describeCandidates(candidates)
        );

        if (std::filesystem::exists(resolveSoundPath(soundId))) {
            log::info("[Pack Download] Skipping '{}' ({}) because it already exists", displayName, soundId);
            ++m_skippedCount;
            notifyProgress(
                fmt::format("Skipped {} (already downloaded) [{} / {}]", displayName, m_downloadIndex, m_soundIds.size()),
                NotificationIcon::Info,
                0.7f
            );
            downloadNextSound();
            return;
        }

        auto outPath = utils::getSfxDownloadPath(soundId, candidates.front());
        log::info(
            "[Pack Download] Output path for '{}' ({}) -> {}",
            displayName,
            soundId,
            geode::utils::string::pathToString(outPath)
        );
        std::error_code ec;
        std::filesystem::create_directories(outPath.parent_path(), ec);
        if (ec) {
            log::error(
                "[Pack Download] Failed to create output directory for '{}' ({}) at {}: {}",
                displayName,
                soundId,
                geode::utils::string::pathToString(outPath.parent_path()),
                ec.message()
            );
            ++m_failedCount;
            notifyProgress(fmt::format("Failed {} (dir error)", displayName), NotificationIcon::Error, 0.8f);
            downloadNextSound();
            return;
        }

        tryDownloadSound(soundId, displayName, candidates, 0);
    }

    void SFXPackCell::tryDownloadSound(std::string const& soundId, std::string const& displayName, std::vector<std::string> const& candidates, size_t candidateIndex) {
        if (candidateIndex >= candidates.size()) {
            log::error(
                "[Pack Download] Exhausted all candidates for '{}' ({}) -> {}",
                displayName,
                soundId,
                describeCandidates(candidates)
            );
            ++m_failedCount;
            notifyProgress(fmt::format("Failed {} (download)", displayName), NotificationIcon::Error, 0.8f);
            downloadNextSound();
            return;
        }

        auto url = utils::makeSfxDownloadUrl(candidates[candidateIndex]);
        if (url.empty()) {
            log::warn(
                "[Pack Download] Candidate {} for '{}' ({}) normalized to empty URL: {}",
                candidateIndex,
                displayName,
                soundId,
                candidates[candidateIndex]
            );
            tryDownloadSound(soundId, displayName, candidates, candidateIndex + 1);
            return;
        }

        log::info(
            "[Pack Download] Attempting candidate {} for '{}' ({}) -> {}",
            candidateIndex,
            displayName,
            soundId,
            url
        );

        web::WebRequest req;
        req.timeout(std::chrono::seconds(20));

        auto aliveToken = m_aliveToken;
        m_packDownloadTask.spawn(
            req.get(url),
            [this, soundId, displayName, candidates, candidateIndex, aliveToken, url](web::WebResponse value) {
                if (!aliveToken || !*aliveToken) {
                    return;
                }

                if (m_cancelRequested) {
                    return;
                }

                if (!value.ok()) {
                    log::warn(
                        "[Pack Download] HTTP failure for '{}' ({}) candidate {} code={} url={}",
                        displayName,
                        soundId,
                        candidateIndex,
                        value.code(),
                        url
                    );
                    tryDownloadSound(soundId, displayName, candidates, candidateIndex + 1);
                    return;
                }

                auto outPath = utils::getSfxDownloadPath(soundId, candidates[candidateIndex]);
                auto writeResult = value.into(outPath);
                if (!writeResult.isOk()) {
                    log::error(
                        "[Pack Download] Failed to write '{}' ({}) candidate {} to {}",
                        displayName,
                        soundId,
                        candidateIndex,
                        geode::utils::string::pathToString(outPath)
                    );
                    tryDownloadSound(soundId, displayName, candidates, candidateIndex + 1);
                    return;
                }

                log::info(
                    "[Pack Download] Saved '{}' ({}) candidate {} to {}",
                    displayName,
                    soundId,
                    candidateIndex,
                    geode::utils::string::pathToString(outPath)
                );
                utils::saveDownloadedSfxMetadata(outPath, soundId, displayName);
                ++m_downloadedCount;
                notifyProgress(
                    fmt::format("Downloaded {} [{} / {}]", displayName, m_downloadIndex, m_soundIds.size()),
                    NotificationIcon::Success,
                    0.7f
                );
                downloadNextSound();
            }
        );
    }

    void SFXPackCell::downloadNextSound() {
        auto aliveToken = m_aliveToken;
        if (!aliveToken || !*aliveToken) {
            return;
        }

        if (m_cancelRequested) {
            return;
        }

        if (m_downloadIndex >= m_soundIds.size()) {
            if (m_failedCount > 0) {
                log::warn(
                    "[Pack Download] Pack '{}' ({}) finished with failures: downloaded={} skipped={} failed={}",
                    m_name,
                    m_sfxId,
                    m_downloadedCount,
                    m_skippedCount,
                    m_failedCount
                );
                m_downloadState = m_preDownloadState;
                m_inUse = m_preDownloadInUse;
            } else {
                log::info(
                    "[Pack Download] Pack '{}' ({}) completed successfully: downloaded={} skipped={} failed={}",
                    m_name,
                    m_sfxId,
                    m_downloadedCount,
                    m_skippedCount,
                    m_failedCount
                );
                registerDownloadedPackMetadata(m_sfxId, m_soundIds);
                recomputePackStateFromSounds(true);
                DSRequest::get()->incrementPackDownload(m_sfxId);
                ++m_serverDownloads;
                if (this->m_downloadsText) {
                    this->m_downloadsText->setString(formatCountCompact(m_serverDownloads).c_str());
                }
            }
            refreshActionButtons();

            notifyProgress(
                fmt::format("Pack done: {} downloaded, {} skipped, {} failed.", m_downloadedCount, m_skippedCount, m_failedCount),
                m_failedCount > 0 ? NotificationIcon::Warning : NotificationIcon::Success,
                1.5f
            );
            return;
        }

        auto soundId = m_soundIds[m_downloadIndex++];
        log::info(
            "[Pack Download] Queueing sound {} of {}: '{}' in pack '{}' ({})",
            m_downloadIndex,
            m_soundIds.size(),
            soundId,
            m_name,
            m_sfxId
        );
        auto sfxInfoUrl = utils::makeSfxDownloadUrl(std::string("/sfx/") + soundId);
        if (sfxInfoUrl.empty()) {
            log::error("[Pack Download] Cannot resolve metadata URL for '{}' ({})", m_name, soundId);
            ++m_failedCount;
            notifyProgress(fmt::format("Failed {} (bad server URL)", soundId), NotificationIcon::Error, 0.8f);
            downloadNextSound();
            return;
        }

        log::info(
            "[Pack Download] Fetching metadata for pack '{}' ({}) sound '{}' from {}",
            m_name,
            m_sfxId,
            soundId,
            sfxInfoUrl
        );

        web::WebRequest req;
        req.timeout(std::chrono::seconds(30));
        m_sfxInfoTask.spawn(
            req.get(sfxInfoUrl),
            [this, soundId, aliveToken](web::WebResponse response) {
                if (!aliveToken || !*aliveToken) {
                    return;
                }

                if (m_cancelRequested) {
                    return;
                }

                if (!response.ok()) {
                    log::warn(
                        "[Pack Download] Metadata request failed for '{}' ({}) HTTP {}",
                        m_name,
                        soundId,
                        response.code()
                    );
                    startSoundDownload(soundId, soundId, { makeSoundRelativeUrl(soundId) });
                    return;
                }

                auto json = response.json();
                if (!json.isOk()) {
                    log::error(
                        "[Pack Download] Metadata response was not JSON for '{}' ({})",
                        m_name,
                        soundId
                    );
                    startSoundDownload(soundId, soundId, { makeSoundRelativeUrl(soundId) });
                    return;
                }

                auto payload = json.unwrap();
                auto sfx = extractSfxObject(payload);
                auto displayName = getStringField(sfx, { "name", "title" }, std::string(soundId));
                std::vector<std::string> candidates;
                appendCandidate(candidates, normalizeDownloadCandidate(getStringField(sfx, { "url" }), soundId));
                appendCandidate(candidates, normalizeDownloadCandidate(getStringField(sfx, { "soundUrl" }), soundId));
                appendCandidate(candidates, normalizeDownloadCandidate(getStringField(sfx, { "downloadUrl" }), soundId));
                appendCandidate(candidates, normalizeDownloadCandidate(getStringField(sfx, { "file" }), soundId));

                log::info(
                    "[Pack Download] Metadata for pack '{}' ({}) sound '{}' resolved name='{}' candidates={}",
                    m_name,
                    m_sfxId,
                    soundId,
                    displayName,
                    describeCandidates(candidates)
                );

                startSoundDownload(soundId, displayName, std::move(candidates));
            }
        );
    }

    void SFXPackCell::onUseToggle(CCObject* sender) {
        if (m_downloadState != DownloadState::Downloaded) {
            return;
        }

        auto toggler = typeinfo_cast<CCMenuItemToggler*>(sender);
        bool enableRequested = toggler ? toggler->isOn() : !m_inUse;
        setPackUsageEnabled(enableRequested);

        notifyProgress(
            fmt::format("{} pack sounds for random pool ({} files).", m_inUse ? "Enabled" : "Disabled", m_soundIds.size()),
            NotificationIcon::Info,
            1.0f
        );
    }

    void SFXPackCell::setPackUsageEnabled(bool enabled) {
        if (m_soundIds.empty()) {
            m_soundIds = getDownloadedPackSoundIds(m_sfxId);
        }

        m_inUse = enabled;

        if (enabled) {
            registerPackUsage(m_sfxId, m_soundIds);
            for (auto const& soundId : m_soundIds) {
                utils::setOnlineSfxPathUsed(resolveSoundPath(soundId), true);
            }
            return;
        }

        disablePackSoundsRespectingOtherPacks();
    }

    void SFXPackCell::disablePackSoundsRespectingOtherPacks() {
        if (m_soundIds.empty()) {
            m_soundIds = getDownloadedPackSoundIds(m_sfxId);
        }

        auto stillNeededByOtherPacks = collectOtherEnabledPackSounds(m_sfxId);
        unregisterPackUsage(m_sfxId);

        for (auto const& soundId : m_soundIds) {
            auto path = resolveSoundPath(soundId);
            if (stillNeededByOtherPacks.find(static_cast<std::string>(soundId)) == stillNeededByOtherPacks.end()) {
                utils::setOnlineSfxPathUsed(path, false);
            }
        }
    }

    void SFXPackCell::onInfoPressed(CCObject*) {
        createQuickPopup(
            m_name.c_str(),
            fmt::format(
                "<cb>Pack:</c> {}\n<cy>Tracks:</c> {}\n<cg>Downloads:</c> {}\n<cl>ID:</c> {}\n\n<cr>Delete will remove every sound in this pack and its metadata.</c>",
                m_name,
                m_trackCount,
                m_serverDownloads,
                m_sfxId
            ),
            "OK", "Delete",
            [this](FLAlertLayer*, bool btn2) {
                if (!btn2) {
                    return;
                }

                m_packDownloadTask.cancel();
                m_cancelRequested = true;

                int removed = 0;
                int missing = 0;
                std::error_code ec;

                for (auto const& soundId : m_soundIds) {
                    auto path = resolveSoundPath(soundId);
                    bool existed = std::filesystem::exists(path);

                    if (existed) {
                        std::filesystem::remove(path, ec);
                        if (!ec) {
                            ++removed;
                        }
                    } else {
                        ++missing;
                    }

                    auto convertedPath = path;
                    convertedPath += ".16.wav";
                    std::filesystem::remove(convertedPath, ec);

                    utils::removeDownloadedSfxMetadata(path);
                }

                disablePackSoundsRespectingOtherPacks();
                removeDownloadedPackMetadata(m_sfxId);

                m_downloadState = DownloadState::NotDownloaded;
                m_inUse = false;
                recomputePackStateFromSounds();
                refreshActionButtons();

                notifyProgress(
                    fmt::format("Pack delete complete: {} removed, {} missing.", removed, missing),
                    NotificationIcon::Success,
                    1.2f
                );
            }
        );
    }
}
