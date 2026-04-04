#include "SearchFilterPopup.hpp"

namespace {
    std::string trim(std::string value) {
        auto isSpace = [](unsigned char c) { return std::isspace(c) != 0; };

        auto begin = std::find_if_not(value.begin(), value.end(), isSpace);
        if (begin == value.end()) {
            return "";
        }

        auto end = std::find_if_not(value.rbegin(), value.rend(), isSpace).base();
        return std::string(begin, end);
    }
}

bool SearchFilterPopup::init(std::string query, bool recent, bool inUse, std::function<void(std::string, bool, bool)> onApply) {
    if (!Popup::init(280.f, 230.f)) {
        return false;
    }

    m_query = trim(std::move(query));
    m_recent = recent;
    m_inUse = inUse;
    m_onApply = std::move(onApply);

    setTitle("Search Filters");

    auto menu = CCMenu::create();
    menu->setPosition({ 0.f, 0.f });
    m_mainLayer->addChild(menu);

    auto queryLabel = CCLabelBMFont::create("Search Query", "goldFont.fnt");
    queryLabel->setAnchorPoint({ 0.f, 0.5f });
    queryLabel->setScale(0.5f);
    queryLabel->setPosition({ 34.f, 146.f });
    m_mainLayer->addChild(queryLabel);

    m_queryInput = TextInput::create(210.f, "Type to search...");
    m_queryInput->setPosition({ m_mainLayer->getContentWidth() / 2.f, 122.f });
    m_queryInput->setCommonFilter(CommonFilter::Any);
    m_queryInput->setMaxCharCount(64);
    m_queryInput->setString(m_query, false);
    m_mainLayer->addChild(m_queryInput);

    auto recentLabel = CCLabelBMFont::create("Recent", "goldFont.fnt");
    recentLabel->setAnchorPoint({ 0.f, 0.5f });
    recentLabel->setScale(0.5f);
    recentLabel->setPosition({ 34.f, 88.f });
    m_mainLayer->addChild(recentLabel);

    auto offSprite = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
    auto onSprite = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
    if (offSprite && onSprite) {
        offSprite->setScale(0.75f);
        onSprite->setScale(0.75f);

        m_recentToggle = CCMenuItemToggler::create(
            offSprite,
            onSprite,
            this,
            menu_selector(SearchFilterPopup::onRecentToggled)
        );
        m_recentToggle->toggle(m_recent);
        m_recentToggle->setPosition({ m_mainLayer->getContentWidth() - 40.f, 88.f });
        menu->addChild(m_recentToggle);

        auto inUseLabel = CCLabelBMFont::create("In Use", "goldFont.fnt");
        inUseLabel->setAnchorPoint({ 0.f, 0.5f });
        inUseLabel->setScale(0.5f);
        inUseLabel->setPosition({ 34.f, 58.f });
        m_mainLayer->addChild(inUseLabel);

        auto inUseOffSprite = CCSprite::createWithSpriteFrameName("GJ_checkOff_001.png");
        auto inUseOnSprite = CCSprite::createWithSpriteFrameName("GJ_checkOn_001.png");
        if (inUseOffSprite && inUseOnSprite) {
            inUseOffSprite->setScale(0.75f);
            inUseOnSprite->setScale(0.75f);

            m_inUseToggle = CCMenuItemToggler::create(
                inUseOffSprite,
                inUseOnSprite,
                this,
                menu_selector(SearchFilterPopup::onInUseToggled)
            );
        }
        if (m_inUseToggle) {
            m_inUseToggle->toggle(m_inUse);
            m_inUseToggle->setPosition({ m_mainLayer->getContentWidth() - 40.f, 58.f });
            menu->addChild(m_inUseToggle);
        }
    }

    auto clearSprite = ButtonSprite::create("Clear", "goldFont.fnt", "GJ_button_01.png", 0.7f);
    auto clearBtn = CCMenuItemSpriteExtra::create(clearSprite, this, menu_selector(SearchFilterPopup::onClear));
    clearBtn->setPosition({ m_mainLayer->getContentWidth() / 2.f - 60.f, 24.f });
    menu->addChild(clearBtn);

    auto applySprite = ButtonSprite::create("Apply", "goldFont.fnt", "GJ_button_01.png", 0.7f);
    auto applyBtn = CCMenuItemSpriteExtra::create(applySprite, this, menu_selector(SearchFilterPopup::onApplyPressed));
    applyBtn->setPosition({ m_mainLayer->getContentWidth() / 2.f + 60.f, 24.f });
    menu->addChild(applyBtn);

    return true;
}

void SearchFilterPopup::applyAndClose() {
    m_query = m_queryInput ? trim(m_queryInput->getString()) : "";
    if (m_onApply) {
        m_onApply(m_query, m_recent, m_inUse);
    }
    onClose(nullptr);
}

void SearchFilterPopup::onClear(CCObject*) {
    m_query.clear();
    m_recent = false;
    m_inUse = false;
    if (m_queryInput) {
        m_queryInput->setString("", false);
    }
    if (m_recentToggle) {
        m_recentToggle->toggle(false);
    }
    if (m_inUseToggle) {
        m_inUseToggle->toggle(false);
    }
    applyAndClose();
}

void SearchFilterPopup::onApplyPressed(CCObject*) {
    applyAndClose();
}

void SearchFilterPopup::onRecentToggled(CCObject*) {
    m_recent = m_recentToggle
        ? !m_recentToggle->isOn()
        : !m_recent;
}

void SearchFilterPopup::onInUseToggled(CCObject*) {
    m_inUse = m_inUseToggle
        ? !m_inUseToggle->isOn()
        : !m_inUse;
}

SearchFilterPopup* SearchFilterPopup::create(std::string query, bool recent, bool inUse, std::function<void(std::string, bool, bool)> onApply) {
    auto ret = new SearchFilterPopup();
    if (ret && ret->init(std::move(query), recent, inUse, std::move(onApply))) {
        ret->autorelease();
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}
