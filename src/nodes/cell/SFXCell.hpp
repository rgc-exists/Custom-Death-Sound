#pragma once

#include <memory>
#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
#include "../../Utils.hpp"


using namespace geode::prelude;

class SFXCell : public CCLayer {
public:
    bool init(
        int index,
        std::string id,
        std::string name,
        std::string url,
        int downloads,
        int32_t createdAt,
        bool isLocal = false,
        bool allowPreview = true,
        std::vector<std::string> tags = {},
        bool showTags = true,
        double lengthSeconds = -1.0,
        matjson::Value sfxObject = matjson::Value()
    );
    static SFXCell* create(
        int index,
        std::string id,
        std::string name,
        std::string url,
        int downloads,
        int32_t createdAt,
        bool isLocal = false,
        bool allowPreview = true,
        std::vector<std::string> tags = {},
        bool showTags = true,
        double lengthSeconds = -1.0,
        matjson::Value sfxObject = matjson::Value()
    );
    void onExit() override;
    virtual void validateDownloadState();

    virtual void onDownloadToggle(CCObject* sender);
    virtual void onUseToggle(CCObject* sender);
    virtual void onInfoPressed(CCObject* sender);
    void onEditPressed(CCObject* sender);
    void onTagBadgePressed(CCObject* sender);
    virtual void finishDownload();

protected:
    enum class DownloadState {
        NotDownloaded,
        Downloading,
        Downloaded,
    };

    virtual void startDownload();
    virtual void cancelDownload();
    void refreshActionButtons();
    void ensurePreviewButton();
    void removePreviewButton();
    void checkPreviewFinished(float dt);
    bool startPreview();
    void stopPreview();

    std::string m_sfxId;
    std::string m_sfxUrl;
    std::string m_name;
    int m_downloadCount = 0;
    int32_t m_createdAt = 0;
    double m_lengthSeconds = -1.0;
    bool m_isLocal = false;
    bool m_allowPreview = true;
    bool m_showTags = true;
    bool m_previewPlaying = false;
    bool m_inUse = false;
    std::vector<std::string> m_tags;
    matjson::Value m_sfxObject;
    DownloadState m_downloadState = DownloadState::NotDownloaded;

    CCMenu* m_menu = nullptr;
    CCMenu* m_tagMenu = nullptr;
    CCMenuItemToggler* m_previewToggle = nullptr;
    CCMenuItemToggler* m_downloadToggle = nullptr;
    CCMenuItemToggler* m_useToggle = nullptr;
    async::TaskHolder<web::WebResponse> m_downloadTask;
    std::shared_ptr<bool> m_aliveToken;
    dsutils::PreviewPlaybackState m_previewState;

    static constexpr int kFinishDownloadActionTag = 0xD50;

public:
    const std::string& getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }
    const std::vector<std::string>& getTags() const { return m_tags; }
    void setTags(const std::vector<std::string>& tags) { m_tags = tags; }
};
