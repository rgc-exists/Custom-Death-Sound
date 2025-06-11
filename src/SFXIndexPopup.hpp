#include "nodes/Border.hpp"
#include "Requests.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SFXIndexPopup : public geode::Popup<>, TableViewCellDelegate {
private:
    LoadingSpinner* m_loadingCircle;
    deathsounds::Border* m_sfxList;

protected:
    bool setup() override {
        this->setTitle("Death SFX Index");

        m_loadingCircle = LoadingSpinner::create(100.f);
        m_mainLayer->addChildAtPosition(m_loadingCircle, Anchor::Center);
        showLoading();

        auto sfxList = ScrollLayer::create({ 340.f, 220.f });
        sfxList->m_contentLayer->setAnchorPoint({ 0.5f, 1.f });
        sfxList->m_contentLayer->addChild(CCSprite::create("GJ_square01.png"));

        m_sfxList = deathsounds::Border::create(sfxList, { 100, 100, 100, 255 }, { 340.f, 220.f }, { 5.f, 5.f });
        m_sfxList->setPosition({ 50.f, 35.f });
        m_sfxList->setVisible(false);
        m_mainLayer->addChild(m_sfxList);

        deathsounds::DSRequest::get()->getTopSFXList([this](const matjson::Value& result) {
            Notification::create(result.dump(), NotificationIcon::Info)->show();
            showResults();
        });

        return true;
    }

    void showLoading() {
        m_loadingCircle->setVisible(true);
    }

    void showResults() {
        m_loadingCircle->setVisible(false);
        m_sfxList->setVisible(true);
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
