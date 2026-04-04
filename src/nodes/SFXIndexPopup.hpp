#pragma once

#include "Border.hpp"
#include "CCLayerMultiplexR.hpp"
#include "geode/GeodeTabSprite.hpp"
#include <Geode/Geode.hpp>
#include <functional>

using namespace geode::prelude;

class SFXIndexPopup : public geode::Popup, SetTextPopupDelegate {
private:
    enum class Tab {
        Downloaded,
        OnlineSounds,
        SoundPacks,
    };

    struct TabWidgets {
        CCLayer* layer = nullptr;
        LoadingSpinner* loading = nullptr;
        deathsounds::Border* border = nullptr;
        ScrollLayer* list = nullptr;
        CCLabelBMFont* error = nullptr;
        CCMenu* errorMenu = nullptr;
        CCMenuItemSpriteExtra* resetToFirstPageBtn = nullptr;
        CCClippingNode* clipping = nullptr;
        CCMenuItemSpriteExtra* searchFilterBtn = nullptr;
    };

    CCLayerMultiplexR* m_tabHost = nullptr;
    TabWidgets m_downloadedWidgets;
    TabWidgets m_onlineWidgets;
    TabWidgets m_packWidgets;
    bool m_recent = false;
    int m_downloadedPage = 1;
    int m_onlinePage = 1;
    int m_packPage = 1;
    CCLabelBMFont* m_pageLabel;
    CCMenuItemSpriteExtra* m_nextPageBtn;
    CCMenuItemSpriteExtra* m_prevPageBtn;
    CCMenuItemSpriteExtra* m_downloadedTabBtn;
    CCMenuItemSpriteExtra* m_onlineTabBtn;
    CCMenuItemSpriteExtra* m_packsTabBtn;
    GeodeTabSprite* m_downloadedTabSprite = nullptr;
    GeodeTabSprite* m_onlineTabSprite = nullptr;
    GeodeTabSprite* m_packsTabSprite = nullptr;
    std::string m_onlineSearchQuery;
    bool m_onlineRecent = false;
    std::string m_packSearchQuery;
    bool m_packRecent = false;
    Tab m_activeTab = Tab::OnlineSounds;

    TabWidgets& widgetsForTab(Tab tab);
    TabWidgets& activeWidgets();
    TabWidgets createTabWidgets();
    void setTabLoading(TabWidgets& widgets);
    void setTabContentVisible(TabWidgets& widgets, bool showPagination);
    void setTabError(TabWidgets& widgets, char const* text, bool showResetToFirstPage = false);
    void setPaginationVisible(bool visible);
    void setPageText(std::string const& text);
    int& pageForTab(Tab tab);
    void populateTabRows(TabWidgets& widgets, std::function<void(int&, float&)> const& appendRow);

protected:
    bool init(bool settingsEnabled);

    void showLoading();
    void loadingError(const char* text);
    void showOnlineResults(const matjson::Value& result);
    void showPackResults(const matjson::Value& result);
    void showDownloadedResults();
    void clearList(TabWidgets& widgets);
    void addSimpleRow(TabWidgets& widgets, int index, const std::string& title, const std::string& subtitle);
    void updateTabVisuals();
    void refreshSearchFilterButtonVisual(Tab tab);
    std::string& queryForTab(Tab tab);
    bool& recentForTab(Tab tab);
    bool filtersSetForTab(Tab tab) const;
    void switchTab(Tab tab);
    void selectDownloadedTab(CCObject*);
    void selectOnlineTab(CCObject*);
    void selectPacksTab(CCObject*);
    void refreshPage(CCObject*);
    void nextPage(CCObject*);
    void prevPage(CCObject*);
    void openSearchFilters(CCObject*);
    void openModSettings(CCObject*);
    void openSfxFolder(CCObject*);
    void resetToFirstPage(CCObject*);

public:
    static SFXIndexPopup* create(bool settingsEnabled);
};
