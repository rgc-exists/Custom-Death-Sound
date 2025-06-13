#pragma once

#include "Border.hpp"
#include "SFXCell.hpp"
#include "../Requests.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SFXIndexPopup : public geode::Popup<>, SetTextPopupDelegate {
private:
    LoadingSpinner* m_loadingCircle;
    deathsounds::Border* m_sfxBorder;
    ScrollLayer* m_sfxList;
    CCLabelBMFont* m_errorText;
    CCClippingNode* m_clippingNode;
    bool m_recent = false;
    int m_currentPage = 1;
    CCLabelBMFont* m_pageLabel;
    CCMenuItemSpriteExtra* m_nextPageBtn;
    CCMenuItemSpriteExtra* m_prevPageBtn;

protected:
    bool setup() override;

    void showLoading();
    void loadingError(const char* text);
    void showResults(const matjson::Value& result);
    void refreshPage(CCObject*);
    void nextPage(CCObject*);
    void prevPage(CCObject*);

public:
    static SFXIndexPopup* create();
};
