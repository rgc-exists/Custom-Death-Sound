#include "SFXPackCell.hpp"
#include "../Requests.hpp"
#include <Geode/ui/Notification.hpp>
#include <Geode/utils/web.hpp>
#include <filesystem>

namespace deathsounds {
    bool SFXPackCell::init(int index, gd::string id, gd::string name, std::vector<gd::string> soundIds, int downloads, int32_t createdAt) {
        if (!SFXCell::init(index, id, name, makeSoundRelativeUrl(id), downloads, createdAt, true, false)) {
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

        auto downloadsText = CCLabelBMFont::create(formatCountCompact(m_serverDownloads).c_str(), "bigFont.fnt");
        downloadsText->setAnchorPoint({ 0.f, 0.5f });
        downloadsText->setScale(0.4f);
        downloadsText->setPosition({ 30.f, 20.f });
        widget->addChild(downloadsText);

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

    SFXPackCell* SFXPackCell::create(int index, gd::string id, gd::string name, std::vector<gd::string> soundIds, int downloads, int32_t createdAt) {
        auto ret = new SFXPackCell();
        if (ret && ret->init(index, std::move(id), std::move(name), std::move(soundIds), downloads, createdAt)) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }

    std::string SFXPackCell::makeSoundRelativeUrl(gd::string const& soundId) {
        return "/sounds/" + soundId + ".wav";
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

    std::filesystem::path SFXPackCell::resolveSoundPath(gd::string const& soundId) const {
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
            auto ext = path.extension().string();
            if (ext != ".wav" && ext != ".ogg" && ext != ".mp3") {
                continue;
            }

            if (path.filename().string().ends_with(".16.wav")) {
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

        for (auto const& soundId : m_soundIds) {
            auto path = resolveSoundPath(soundId);
            if (!std::filesystem::exists(path)) {
                m_downloadState = DownloadState::NotDownloaded;
                m_inUse = false;
                utils::setOnlineSfxPathUsed(path, false);
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
        if (auto notif = geode::Notification::create(message, icon, time)) {
            notif->show();
        }
    }

    void SFXPackCell::onDownloadToggle(CCObject* sender) {
        if (m_downloadState == DownloadState::Downloaded) {
            return;
        }

        auto toggler = typeinfo_cast<CCMenuItemToggler*>(sender);
        bool wantsDownloading = toggler
            ? !toggler->isOn()
            : (m_downloadState == DownloadState::NotDownloaded);

        if (wantsDownloading && m_downloadState == DownloadState::NotDownloaded) {
            startPackDownload();
            return;
        }

        if (!wantsDownloading && m_downloadState == DownloadState::Downloading) {
            cancelPackDownload();
        }
    }

    void SFXPackCell::startPackDownload() {
        if (m_soundIds.empty()) {
            notifyProgress("Pack has no sounds to download.", NotificationIcon::Warning, 1.0f);
            return;
        }

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

    void SFXPackCell::cancelPackDownload() {
        m_cancelRequested = true;
        m_packDownloadTask.cancel();
        m_downloadState = m_preDownloadState;
        m_inUse = m_preDownloadInUse;
        refreshActionButtons();
        notifyProgress("Pack download cancelled.", NotificationIcon::Warning, 0.8f);
    }

    void SFXPackCell::downloadNextSound() {
        if (m_cancelRequested) {
            return;
        }

        if (m_downloadIndex >= m_soundIds.size()) {
            if (m_failedCount > 0) {
                m_downloadState = m_preDownloadState;
                m_inUse = m_preDownloadInUse;
            } else {
                recomputePackStateFromSounds(true);
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
        DSRequest::get()->getSFXInfo(
            soundId,
            [this, soundId](matjson::Value const& payload) {
                if (m_cancelRequested) {
                    return;
                }

                if (!payload.contains("sfx")) {
                    ++m_failedCount;
                    notifyProgress(fmt::format("Failed {} (lookup)", soundId), NotificationIcon::Error, 0.8f);
                    downloadNextSound();
                    return;
                }

                auto sfx = payload["sfx"];
                auto relativeUrl = sfx.contains("url")
                    ? sfx["url"].asString().unwrapOr("")
                    : std::string();
                auto displayName = sfx.contains("name")
                    ? sfx["name"].asString().unwrapOr(std::string(soundId))
                    : std::string(soundId);

                if (relativeUrl.empty()) {
                    relativeUrl = makeSoundRelativeUrl(soundId);
                }

                auto outPath = utils::getSfxDownloadPath(soundId, relativeUrl);
                if (std::filesystem::exists(outPath)) {
                    ++m_skippedCount;
                    notifyProgress(
                        fmt::format("Skipped {} (already downloaded) [{} / {}]", displayName, m_downloadIndex, m_soundIds.size()),
                        NotificationIcon::Info,
                        0.7f
                    );
                    downloadNextSound();
                    return;
                }

                std::error_code ec;
                std::filesystem::create_directories(outPath.parent_path(), ec);
                if (ec) {
                    ++m_failedCount;
                    notifyProgress(fmt::format("Failed {} (dir error)", displayName), NotificationIcon::Error, 0.8f);
                    downloadNextSound();
                    return;
                }

                auto url = utils::makeSfxDownloadUrl(relativeUrl);
                if (url.empty()) {
                    ++m_failedCount;
                    notifyProgress(fmt::format("Failed {} (bad URL)", displayName), NotificationIcon::Error, 0.8f);
                    downloadNextSound();
                    return;
                }

                web::WebRequest req;
                req.timeout(std::chrono::seconds(20));

                m_packDownloadTask.spawn(
                    req.get(url),
                    [this, soundId, displayName, outPath](web::WebResponse value) {
                        if (m_cancelRequested) {
                            return;
                        }

                        if (!value.ok()) {
                            ++m_failedCount;
                            notifyProgress(fmt::format("Failed {} (HTTP {})", displayName, value.code()), NotificationIcon::Error, 0.8f);
                            downloadNextSound();
                            return;
                        }

                        auto writeResult = value.into(outPath);
                        if (!writeResult.isOk()) {
                            ++m_failedCount;
                            notifyProgress(fmt::format("Failed saving {}", displayName), NotificationIcon::Error, 0.8f);
                            downloadNextSound();
                            return;
                        }

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
            },
            [this, soundId](matjson::Value const&) {
                if (m_cancelRequested) {
                    return;
                }

                ++m_failedCount;
                notifyProgress(fmt::format("Failed {} (lookup)", soundId), NotificationIcon::Error, 0.8f);
                downloadNextSound();
            }
        );
    }

    void SFXPackCell::onUseToggle(CCObject* sender) {
        if (m_downloadState != DownloadState::Downloaded) {
            return;
        }

        auto toggler = typeinfo_cast<CCMenuItemToggler*>(sender);
        bool enableRequested = toggler ? toggler->isOn() : !m_inUse;
        m_inUse = enableRequested;

        int affected = 0;
        for (auto const& soundId : m_soundIds) {
            auto path = resolveSoundPath(soundId);
            utils::setOnlineSfxPathUsed(path, enableRequested);
            ++affected;
        }

        notifyProgress(
            fmt::format("{} pack sounds for random pool ({} files).", m_inUse ? "Enabled" : "Disabled", affected),
            NotificationIcon::Info,
            1.0f
        );
    }

    void SFXPackCell::onInfoPressed(CCObject*) {
        geode::createQuickPopup(
            m_name.c_str(),
            fmt::format(
                "<cb>Pack:</c> {}\n<cy>Tracks:</c> {}\n<cg>Downloads:</c> {}\n<cl>ID:</c> {}\n\n<cr>Delete will remove every sound in this pack and its metadata.</c>",
                m_name,
                m_trackCount,
                m_serverDownloads,
                m_sfxId
            ),
            "Delete", "OK",
            [this](FLAlertLayer*, bool btn2) {
                if (btn2) {
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
                    utils::setOnlineSfxPathUsed(path, false);
                }

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
