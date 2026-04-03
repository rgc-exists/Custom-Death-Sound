#pragma once

#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
#include "../Utils.hpp"

using namespace geode::prelude;

namespace deathsounds {
    class SFXCell : public CCLayer {
    public:
        bool init(int index, std::string id, std::string name, std::string url, int downloads, int32_t createdAt, bool isLocal = false/*, int likes, int dislikes*/);
        static SFXCell* create(int index, std::string id, std::string name, std::string url, int downloads, int32_t createdAt, bool isLocal = false/*, int likes, int dislikes*/);
        void onExit() override;

        void onDownloadToggle(CCObject* sender);
        void onUseToggle(CCObject* sender);
        void onInfoPressed(CCObject* sender);
        void finishDownload();

    private:
        enum class DownloadState {
            NotDownloaded,
            Downloading,
            Downloaded,
        };

        void startDownload();
        void cancelDownload();
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
        bool m_isLocal = false;
        bool m_previewPlaying = false;
        bool m_inUse = false;
        DownloadState m_downloadState = DownloadState::NotDownloaded;

        CCMenu* m_menu = nullptr;
        CCMenuItemToggler* m_previewToggle = nullptr;
        CCMenuItemToggler* m_downloadToggle = nullptr;
        CCMenuItemToggler* m_useToggle = nullptr;
        async::TaskHolder<web::WebResponse> m_downloadTask;
        utils::PreviewPlaybackState m_previewState;

        static constexpr int kFinishDownloadActionTag = 0xD50;
    };
}
