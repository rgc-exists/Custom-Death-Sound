#include "nodes/Border.hpp"
#include "Requests.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SFXIndexPopup : public geode::Popup<>, TableViewCellDelegate {
private:
    LoadingSpinner* m_loadingCircle;
    deathsounds::Border* m_sfxList;
    CCLabelBMFont* m_errorText;

protected:
    bool setup() override {
        this->setTitle("Death SFX Index");

        auto menu = CCMenu::create();
        menu->setPosition({ 0.f, 0.f });
        menu->setAnchorPoint({ 0.f, 0.f });
        m_mainLayer->addChild(menu);

        m_loadingCircle = LoadingSpinner::create(100.f);
        m_mainLayer->addChildAtPosition(m_loadingCircle, Anchor::Center);
        
        auto sfxList = ScrollLayer::create({ 340.f, 220.f });
        sfxList->m_contentLayer->setAnchorPoint({ 0.5f, 1.f });
        sfxList->m_contentLayer->addChild(CCSprite::create("GJ_square01.png"));
        
        m_sfxList = deathsounds::Border::create(sfxList, { 100, 100, 100, 255 }, { 340.f, 220.f }, { 5.f, 5.f });
        m_sfxList->setPosition({ 50.f, 35.f });
        m_sfxList->setVisible(false);
        m_mainLayer->addChild(m_sfxList);

        m_errorText = CCLabelBMFont::create("", "bigFont.fnt", 350.f);
        m_errorText->setPosition(m_mainLayer->getContentSize() / 2);
        m_errorText->setScale(0.5f);
        m_mainLayer->addChild(m_errorText);
        
        auto refreshButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_updateBtn_001.png"),
            this,
            menu_selector(SFXIndexPopup::refreshPage)
        );
        menu->addChild(refreshButton);
        
        refreshPage(nullptr);

        return true;
    }

    void showLoading() {
        m_loadingCircle->setVisible(true);
        m_sfxList->setVisible(false);
        m_errorText->setVisible(false);
    }

    void loadingError(const char* text) {
        m_loadingCircle->setVisible(false);
        m_errorText->setString(text);
        m_errorText->setVisible(true);
    }

    void showResults(const matjson::Value& result) {
        m_loadingCircle->setVisible(false);
        m_sfxList->setVisible(true);
        m_errorText->setVisible(false);
    }

    void refreshPage(CCObject*) {
        showLoading();
        deathsounds::DSRequest::get()->getTopSFXList([this](const matjson::Value& result) {
            showResults(result);
        }, [this](const matjson::Value& result) {
            std::string errorStr = result["error"].dump();
            if (!errorStr.empty() && errorStr.front() == '"' && errorStr.back() == '"') {
                errorStr = errorStr.substr(1, errorStr.size() - 2);
            }
            loadingError(errorStr.c_str());
        });
    }

public:
    static SFXIndexPopup* create() {
        auto ret = new SFXIndexPopup();
        if (ret->initAnchored(440.f, 290.f, "GJ_square02.png")) {
            ret->autorelease();
            return ret;
        }

        delete ret;
        return nullptr;
    }
};
