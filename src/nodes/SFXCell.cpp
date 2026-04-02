#include "SFXCell.hpp"
#include "../Utils.hpp"
#include <Geode/utils/web.hpp>

namespace deathsounds {
    namespace {
        std::unordered_set<std::string> s_downloadedSfx;
    }

    bool SFXCell::init(int index, std::string id, std::string name, std::string url, int downloads, int32_t createdAt/*, int likes, int dislikes*/) {
        if (!CCLayer::init()) {
            return false;
        }

        m_sfxId = id;
        m_sfxUrl = url;
        m_name = name;
        m_downloadCount = downloads;
        m_createdAt = createdAt;
        auto existingPath = utils::getSfxDownloadPath(m_sfxId, m_sfxUrl);
        bool alreadyDownloaded = std::filesystem::exists(existingPath);
        if (alreadyDownloaded) {
            s_downloadedSfx.insert(m_sfxId);
        }
        m_downloadState = (alreadyDownloaded || s_downloadedSfx.contains(m_sfxId))
            ? DownloadState::Downloaded
            : DownloadState::NotDownloaded;
        m_inUse = utils::isOnlineSfxPathUsed(existingPath);

        setMouseEnabled(true);
        setTouchEnabled(true);

        setContentSize({ 340.f, 80.f });

        ccColor3B bgColor = (index % 2 == 0) ? ccc3(75, 75, 75) : ccc3(50, 50, 50);
        auto layerBG = CCLayerColor::create(ccc4(bgColor.r, bgColor.g, bgColor.b, 255));
        layerBG->setContentSize(getContentSize());
        addChild(layerBG);

        auto widget = CCLayer::create();
        widget->setContentSize({ getContentWidth() * 0.8f, getContentHeight() - 20.f });
        widget->setPosition({ getContentWidth() * 0.1f, 10.f });
        addChild(widget);

        m_menu = CCMenu::create();
        m_menu->setPosition({ 0.f, 0.f });
        m_menu->setContentSize(widget->getContentSize());
        widget->addChild(m_menu, 500);
        
        auto widgetBG = CCScale9Sprite::create("GJ_square01.png");
        widgetBG->setContentSize(widget->getContentSize());
        widgetBG->setAnchorPoint({ 0.f, 0.f });
        widget->addChild(widgetBG);

        const float previewX = m_menu->getContentWidth() - 30.f;
        const float previewY = m_menu->getContentHeight() / 2;
        const float actionButtonGap = 38.f;
        const float actionSpriteScale = 0.8f;
        const float infoSpriteScale = 0.6f;

        auto downloadOffSprite = CCSprite::createWithSpriteFrameName("GJ_downloadBtn_001.png");
        auto downloadOnSprite = CCSprite::createWithSpriteFrameName("GJ_cancelDownloadBtn_001.png");
        downloadOffSprite->setScale(actionSpriteScale);
        downloadOnSprite->setScale(actionSpriteScale);

        m_downloadToggle = CCMenuItemExt::createToggler(
            downloadOnSprite,
            downloadOffSprite,
            [this](CCMenuItemToggler*) {
                this->onDownloadToggle(nullptr);
            }
        );
        m_downloadToggle->toggle(false);
        m_downloadToggle->setPosition({ previewX - actionButtonGap, previewY });
        m_menu->addChild(m_downloadToggle);

        auto useOffSprite = CCSprite::createWithSpriteFrameName("GJ_selectSongBtn_001.png");
        auto useOnSprite = CCSprite::createWithSpriteFrameName("GJ_selectSongOnBtn_001.png");
        useOffSprite->setScale(actionSpriteScale);
        useOnSprite->setScale(actionSpriteScale);

        m_useToggle = CCMenuItemExt::createToggler(
            useOnSprite,
            useOffSprite,
            [this](CCMenuItemToggler*) {
                this->onUseToggle(nullptr);
            }
        );
        m_useToggle->toggle(false);
        m_useToggle->setPosition(m_downloadToggle->getPosition());
        m_menu->addChild(m_useToggle);

        refreshActionButtons();

        std::string displayName = name;
        auto nameLabel = CCLabelBMFont::create(displayName.c_str(), "bigFont.fnt");
        nameLabel->setAnchorPoint({ 0.f, 1.f });
        nameLabel->setPosition({ 10.f, widget->getContentHeight() - 10.f });
        float nameBaseScale = 0.5f;
        float actionVisualHalfWidth = m_downloadToggle->getContentWidth() * actionSpriteScale * 0.5f;
        float previewLeftEdge = previewX - actionVisualHalfWidth;
        float actionLeftEdge = m_downloadToggle->getPositionX() - actionVisualHalfWidth;
        float maxNameWidth = std::min(previewLeftEdge, actionLeftEdge) - nameLabel->getPositionX() - 8.f;
        float targetScale = nameBaseScale;
        if (maxNameWidth > 0.f && (nameLabel->getContentWidth() * nameBaseScale) > maxNameWidth) {
            targetScale = maxNameWidth / nameLabel->getContentWidth();
        }
        nameLabel->setScale(targetScale);
        widget->addChild(nameLabel);

        auto downloadsSprite = CCSprite::createWithSpriteFrameName("GJ_sDownloadIcon_001.png");
        downloadsSprite->setPosition({ 20.f, 20.f });
        widget->addChild(downloadsSprite);

        auto formatDownloads = [](int downloads) -> std::string {
            char buf[16];
            if (downloads >= 1000000000)
            std::snprintf(buf, sizeof(buf), "%.1fB", downloads / 1000000000.0);
            else if (downloads >= 1000000)
            std::snprintf(buf, sizeof(buf), "%.1fM", downloads / 1000000.0);
            else if (downloads >= 1000)
            std::snprintf(buf, sizeof(buf), "%.1fK", downloads / 1000.0);
            else
            std::snprintf(buf, sizeof(buf), "%d", downloads);
            std::string s(buf);
            if (s.find('.') != std::string::npos) {
            s.erase(s.find_last_not_of('0') + 1, std::string::npos);
            if (s.back() == '.') s.pop_back();
            }
            return s;
        };

        auto downloadsText = CCLabelBMFont::create(formatDownloads(downloads).c_str(), "bigFont.fnt");
        downloadsText->setAnchorPoint({ 0.f, 0.5f });
        downloadsText->setScale(0.4f);
        downloadsText->setPosition({ 30.f, 20.f });
        widget->addChild(downloadsText);

        /*CCSprite* likesSprite;
        if ((likes - dislikes) >= 0) {
            likesSprite = CCSprite::createWithSpriteFrameName("GJ_sLikeIcon_001.png");
        } else {
            likesSprite = CCSprite::createWithSpriteFrameName("GJ_dislikesIcon_001.png");
            likesSprite->setScale(0.6f);
        }
        likesSprite->setPosition({ 90.f, 20.f });
        widget->addChild(likesSprite);

        auto likesText = CCLabelBMFont::create(std::to_string(likes - dislikes).c_str(), "bigFont.fnt");
        likesText->setAnchorPoint({ 0.f, 0.5f });
        likesText->setScale(0.4f);
        likesText->setPosition({ 100.f, 20.f });
        widget->addChild(likesText);*/

        auto infoIcon = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
        infoIcon->setScale(infoSpriteScale);
        auto infoButton = CCMenuItemSpriteExtra::create(
            infoIcon,
            this,
            menu_selector(SFXCell::onInfoPressed)
        );
        infoButton->setPosition(m_menu->getContentSize() - 10.f);
        m_menu->addChild(infoButton);

        this->schedule(schedule_selector(SFXCell::checkPreviewFinished), 0.1f);

        return true;
    }

    SFXCell* SFXCell::create(int index, std::string id, std::string name, std::string url, int downloads, int32_t createdAt/*, int likes, int dislikes*/) {
        auto ret = new SFXCell();
        if (ret && ret->init(index, id, name, url, downloads, createdAt/*, likes, dislikes*/)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    void SFXCell::onExit() {
        this->unschedule(schedule_selector(SFXCell::checkPreviewFinished));
        stopPreview();
        CCLayer::onExit();
    }

    void SFXCell::startDownload() {
        m_downloadTask.cancel();
        m_downloadState = DownloadState::Downloading;
        refreshActionButtons();

        auto outPath = utils::getSfxDownloadPath(m_sfxId, m_sfxUrl);
        auto url = utils::makeSfxDownloadUrl(m_sfxUrl);
        auto absPath = std::filesystem::absolute(outPath);

        if (url.empty()) {
            log::error("Cannot download SFX {}: empty URL", m_sfxId);
            m_downloadState = DownloadState::NotDownloaded;
            refreshActionButtons();
            return;
        }

        log::info("[SFX Download] Starting '{}' ({}) -> {}:1", m_name, m_sfxId, absPath.string());

        std::error_code ec;
        std::filesystem::create_directories(outPath.parent_path(), ec);
        if (ec) {
            log::error("Failed creating SFX download directory: {}", ec.message());
            m_downloadState = DownloadState::NotDownloaded;
            refreshActionButtons();
            return;
        }

        web::WebRequest req;
        req.timeout(std::chrono::seconds(60));

        m_downloadTask.spawn(
            req.get(url),
            [this, outPath](web::WebResponse value) {
                auto absPath = std::filesystem::absolute(outPath);
                if (!value.ok()) {
                    log::error("[SFX Download] Failed '{}' ({}) HTTP {} -> {}:1", m_name, m_sfxId, value.code(), absPath.string());
                    m_downloadState = DownloadState::NotDownloaded;
                    refreshActionButtons();
                    return;
                }

                auto writeResult = value.into(outPath);
                if (!writeResult.isOk()) {
                    log::error("[SFX Download] Failed saving '{}' ({}) -> {}:1", m_name, m_sfxId, absPath.string());
                    m_downloadState = DownloadState::NotDownloaded;
                    refreshActionButtons();
                    return;
                }

                log::info("[SFX Download] Completed '{}' ({}) -> {}:1", m_name, m_sfxId, absPath.string());

                finishDownload();
            }
        );
    }

    void SFXCell::cancelDownload() {
        m_downloadTask.cancel();

        auto absPath = std::filesystem::absolute(utils::getSfxDownloadPath(m_sfxId, m_sfxUrl));
        log::info("[SFX Download] Canceled '{}' ({}) -> {}:1", m_name, m_sfxId, absPath.string());

        stopPreview();

        m_downloadState = DownloadState::NotDownloaded;
        m_inUse = false;
        utils::setOnlineSfxPathUsed(utils::getSfxDownloadPath(m_sfxId, m_sfxUrl), false);
        s_downloadedSfx.erase(m_sfxId);
        refreshActionButtons();
    }

    void SFXCell::finishDownload() {
        auto downloadPath = utils::getSfxDownloadPath(m_sfxId, m_sfxUrl);
        utils::saveDownloadedSfxMetadata(downloadPath, m_sfxId, m_name);
        m_downloadState = DownloadState::Downloaded;
        m_inUse = false;
        s_downloadedSfx.insert(m_sfxId);
        utils::setOnlineSfxPathUsed(downloadPath, false);
        auto absPath = std::filesystem::absolute(downloadPath);
        log::info("[SFX Download] Ready for use '{}' ({}) at {}:1", m_name, m_sfxId, absPath.string());
        refreshActionButtons();
    }

    void SFXCell::onDownloadToggle(CCObject*) {
        if (m_downloadState == DownloadState::Downloading) {
            cancelDownload();
            return;
        }
        if (m_downloadState == DownloadState::NotDownloaded) {
            startDownload();
        }
    }

    void SFXCell::onUseToggle(CCObject*) {
        if (m_downloadState != DownloadState::Downloaded) {
            return;
        }

        m_inUse = !m_inUse;
        utils::setOnlineSfxPathUsed(utils::getSfxDownloadPath(m_sfxId, m_sfxUrl), m_inUse);

        auto selectedPaths = utils::getUsedOnlineSfxPaths();
        log::info("[SFX Use] {} '{}' ({}) for explode_11.ogg random pool ({} selected)",
            m_inUse ? "Enabled" : "Disabled",
            m_name,
            m_sfxId,
            selectedPaths.size());

        refreshActionButtons();
    }

    void SFXCell::onInfoPressed(CCObject*) {
        geode::createQuickPopup(
            m_name.c_str(),
            fmt::format("<cb>Name (full):</c> {}\n<cy>Uploaded:</c> {}\n<cg>Downloads:</c> {}",
                m_name, deathsounds::utils::formatDate(m_createdAt), m_downloadCount),
            "Delete", "OK",
            [this](FLAlertLayer*, bool btn2) {
                if (btn2) {
                    return;
                }

                auto downloadPath = utils::getSfxDownloadPath(m_sfxId, m_sfxUrl);
                m_downloadTask.cancel();
                std::error_code ec;
                std::filesystem::remove(downloadPath, ec);
                std::filesystem::remove(utils::getSfxPlayablePath(m_sfxId, m_sfxUrl), ec);
                utils::removeDownloadedSfxMetadata(downloadPath);

                stopPreview();

                m_downloadState = DownloadState::NotDownloaded;
                m_inUse = false;
                utils::setOnlineSfxPathUsed(downloadPath, false);
                s_downloadedSfx.erase(m_sfxId);
                refreshActionButtons();
            }
        );
    }

    void SFXCell::refreshActionButtons() {
        if (!m_downloadToggle || !m_useToggle) {
            return;
        }

        if (!m_menu) {
            return;
        }

        const float previewX = m_menu->getContentWidth() - 30.f;
        const float previewY = m_menu->getContentHeight() / 2;
        const float actionButtonGap = 38.f;

        bool isDownloaded = m_downloadState == DownloadState::Downloaded;
        bool isDownloading = m_downloadState == DownloadState::Downloading;

        m_downloadToggle->setVisible(!isDownloaded);
        m_downloadToggle->setEnabled(!isDownloaded);
        m_downloadToggle->toggle(isDownloading);
        m_downloadToggle->setPosition({ previewX, previewY });

        m_useToggle->setVisible(isDownloaded);
        m_useToggle->setEnabled(isDownloaded);
        m_useToggle->toggle(m_inUse);
        m_useToggle->setPosition({ previewX - actionButtonGap, previewY });

        if (isDownloaded) {
            ensurePreviewButton();
        }
        else {
            removePreviewButton();
        }
    }

    void SFXCell::ensurePreviewButton() {
        if (!m_menu || m_previewToggle) {
            return;
        }

        m_previewToggle = CCMenuItemExt::createToggler(
            [] {
                auto spr = CCSprite::createWithSpriteFrameName("GJ_stopMusicBtn_001.png");
                spr->setScale(0.8f);
                return spr;
            }(),
            [] {
                auto spr = CCSprite::createWithSpriteFrameName("GJ_playMusicBtn_001.png");
                spr->setScale(0.8f);
                return spr;
            }(),
            [this](CCMenuItemToggler* toggler) {
                if (this->m_previewState.playing) {
                    this->stopPreview();
                    toggler->toggle(false);
                    return;
                }

                toggler->toggle(this->startPreview());
            }
        );

        m_previewToggle->setPosition({ m_menu->getContentWidth() - 30.f, m_menu->getContentHeight() / 2 });
        m_menu->addChild(m_previewToggle);
        m_previewToggle->toggle(false);
    }

    void SFXCell::checkPreviewFinished(float) {
        if (!m_previewState.playing || !m_previewState.channel) {
            return;
        }

        bool isPlaying = false;
        FMOD_RESULT result = m_previewState.channel->isPlaying(&isPlaying);
        if (result != FMOD_OK || !isPlaying) {
            stopPreview();
            if (m_previewToggle) {
                m_previewToggle->toggle(false);
            }
        }
    }

    void SFXCell::removePreviewButton() {
        if (!m_previewToggle) {
            return;
        }

        stopPreview();

        m_previewToggle->removeFromParent();
        m_previewToggle = nullptr;
    }

    bool SFXCell::startPreview() {
        auto originalPath = utils::getSfxDownloadPath(m_sfxId, m_sfxUrl);
        return utils::startPreviewPlayback(m_previewState, originalPath, m_name, m_sfxId);
    }

    void SFXCell::stopPreview() {
        utils::stopPreviewPlayback(m_previewState);
    }
}
