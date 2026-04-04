#pragma once

#include "SFXCell.hpp"

namespace deathsounds {
    class SFXPackCell : public SFXCell {
    public:
        bool init(int index, gd::string id, gd::string name, std::vector<gd::string> soundIds, int downloads, int32_t createdAt);
        static SFXPackCell* create(int index, gd::string id, gd::string name, std::vector<gd::string> soundIds, int downloads, int32_t createdAt);

        void validateDownloadState() override;
        void onDownloadToggle(CCObject* sender) override;
        void onUseToggle(CCObject* sender) override;
        void onInfoPressed(CCObject* sender) override;

    private:
        std::vector<gd::string> m_soundIds;
        int m_trackCount = 0;
        int m_serverDownloads = 0;
        CCLabelBMFont* m_downloadsText = nullptr;
        size_t m_downloadIndex = 0;
        int m_downloadedCount = 0;
        int m_skippedCount = 0;
        int m_failedCount = 0;
        bool m_cancelRequested = false;
        DownloadState m_preDownloadState = DownloadState::NotDownloaded;
        bool m_preDownloadInUse = false;
        async::TaskHolder<web::WebResponse> m_packDownloadTask;

        static std::string makeSoundRelativeUrl(gd::string const& soundId);
        static std::string formatCountCompact(int value);
        std::filesystem::path resolveSoundPath(gd::string const& soundId) const;
        void recomputePackStateFromSounds(bool forceStateUpdate = false);
        void startPackDownload();
        void cancelPackDownload();
        void downloadNextSound();
        void notifyProgress(std::string const& message, NotificationIcon icon = NotificationIcon::Info, float time = 0.8f);
        void setPackUsageEnabled(bool enabled);
        void disablePackSoundsRespectingOtherPacks();
    };
}
