#include "nodes/Border.hpp"
#include "nodes/SFXCell.hpp"
#include "Requests.hpp"
#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SFXIndexPopup : public geode::Popup<>, TableViewCellDelegate {
private:
    LoadingSpinner* m_loadingCircle;
    deathsounds::Border* m_sfxBorder;
    ScrollLayer* m_sfxList;
    CCLabelBMFont* m_errorText;
    CCClippingNode* m_clippingNode;
    bool m_recent = false;

protected:
    bool setup() override {
        this->setTitle("Death SFX Index");

        auto menu = CCMenu::create();
        menu->setPosition({ 0.f, 0.f });
        menu->setAnchorPoint({ 0.f, 0.f });
        m_mainLayer->addChild(menu);

        m_loadingCircle = LoadingSpinner::create(100.f);
        m_mainLayer->addChildAtPosition(m_loadingCircle, Anchor::Center);

        m_sfxList = ScrollLayer::create({ 340.f, 220.f });
        // m_sfxList->m_contentLayer->setAnchorPoint({ 0.5f, 1.f });
        
        auto columnLayout = ColumnLayout::create();
        columnLayout->setAxisReverse(true)
                    ->setAutoGrowAxis(m_sfxList->getContentHeight())
                    ->setCrossAxisOverflow(false)
                    ->setAxisAlignment(AxisAlignment::Center)
                    ->setGap(0.f);
        m_sfxList->m_contentLayer->setLayout(columnLayout);

        m_clippingNode = CCClippingNode::create();
        m_clippingNode->setContentSize({ 340.f, 220.f });
        m_clippingNode->setAnchorPoint({ 0.f, 0.f });
        m_clippingNode->setPosition({ 50.f, 35.f });

        auto stencil = CCLayerColor::create(ccc4(255, 255, 255, 255), 340.f, 220.f);
        stencil->setAnchorPoint({ 0.f, 0.f });
        m_clippingNode->setStencil(stencil);

        m_sfxList->setPosition({ 0.f, 0.f });
        m_clippingNode->addChild(m_sfxList);

        m_sfxBorder = deathsounds::Border::create(m_sfxList, { 75, 75, 75, 255 }, { 340.f, 220.f });
        m_sfxBorder->setPosition({ 0.f, 0.f });
        m_sfxBorder->setVisible(false);
        m_clippingNode->addChild(m_sfxBorder);

        m_mainLayer->addChild(m_clippingNode);

        m_errorText = CCLabelBMFont::create("", "bigFont.fnt", 350.f);
        m_errorText->setPosition(m_mainLayer->getContentSize() / 2);
        m_errorText->setScale(0.5f);
        m_mainLayer->addChild(m_errorText);
        
        auto refreshSprite = CCSprite::createWithSpriteFrameName("GJ_updateBtn_001.png");
        refreshSprite->setScale(0.75f);

        auto refreshButton = CCMenuItemSpriteExtra::create(
            refreshSprite,
            this,
            menu_selector(SFXIndexPopup::refreshPage)
        );
        refreshButton->setPosition({ m_mainLayer->getContentWidth() - (refreshButton->getContentWidth() * 0.75f), (refreshButton->getContentHeight() * 0.75f ) });
        menu->addChild(refreshButton);
        
        refreshPage(nullptr);

        return true;
    }

    void showLoading() {
        m_loadingCircle->setVisible(true);
        m_sfxBorder->setVisible(false);
        m_clippingNode->setVisible(false);
        m_errorText->setVisible(false);
    }

    void loadingError(const char* text) {
        m_loadingCircle->setVisible(false);
        m_errorText->setString(text);
        m_errorText->setVisible(true);
    }

    void showResults(const matjson::Value& result) {
        m_loadingCircle->setVisible(false);
        m_errorText->setVisible(false);

        m_clippingNode->setVisible(true);

        m_sfxList->m_contentLayer->removeAllChildrenWithCleanup(true);

        float totalHeight = 0.f;

        int index = 0;
        for (auto& sfxItem : result) {
            auto cellTest = deathsounds::SFXCell::create(index, sfxItem["id"].asString().unwrap(), sfxItem["name"].asString().unwrap(), sfxItem["downloads"].asInt().unwrap(), sfxItem["createdAt"].asInt().unwrap());
            m_sfxList->m_contentLayer->addChild(cellTest);
            totalHeight += cellTest->getContentHeight();
            m_sfxList->m_contentLayer->setContentSize({ m_sfxList->m_contentLayer->getContentSize().width, totalHeight });
            ++index;
        }

        m_sfxList->m_contentLayer->updateLayout();
        m_sfxList->scrollToTop();

        m_sfxBorder->setVisible(true);
    }

    void refreshPage(CCObject*) {
        showLoading();
        deathsounds::DSRequest::get()->getTopSFXList(m_recent, [this](const matjson::Value& result) {
            showResults(result);
        }, [this](const matjson::Value& result) {
            std::string errorStr = result["error"].asString().unwrap();
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
