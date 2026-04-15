#pragma once

#include "SFXCell.hpp"
#include "../popup/EditSoundPackPopup.hpp"
#include "../popup/EditSoundPackPopup.hpp"

class SFXPackCell : public SFXCell {
public:
    bool init(int index, std::string id, std::string name, std::vector<std::string> soundIds, int downloads, int32_t createdAt);
    static SFXPackCell* create(int index, std::string id, std::string name, std::vector<std::string> soundIds, int downloads, int32_t createdAt);

    void validateDownloadState() override;
    void onDownloadToggle(CCObject* sender) override;
    void onUseToggle(CCObject* sender) override;
    void onInfoPressed(CCObject* sender) override;
    void onEditPressed(CCObject* sender);
    void onExit() override;

    const std::string& getName() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }
    const std::vector<std::string>& getSoundIds() const { return m_soundIds; }
    void setSoundIds(const std::vector<std::string>& ids) { m_soundIds = ids; }

private:
    std::vector<std::string> m_soundIds;
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
    async::TaskHolder<web::WebResponse> m_sfxInfoTask;
    async::TaskHolder<web::WebResponse> m_packDownloadTask;

    static std::string makeSoundRelativeUrl(std::string const& soundId);
    static std::string formatCountCompact(int value);
    std::filesystem::path resolveSoundPath(std::string const& soundId) const;
    void recomputePackStateFromSounds(bool forceStateUpdate = false);
    void startPackDownload();
    void cancelPackDownload();
    void startSoundDownload(std::string const& soundId, std::string const& displayName, std::vector<std::string> candidates);
    void tryDownloadSound(std::string const& soundId, std::string const& displayName, std::vector<std::string> const& candidates, size_t candidateIndex);
    void downloadNextSound();
    void notifyProgress(std::string const& message, NotificationIcon icon = NotificationIcon::Info, float time = 0.8f);
    void setPackUsageEnabled(bool enabled);
    void disablePackSoundsRespectingOtherPacks();
    void refreshActionButtonsDeferred(float dt);
};
