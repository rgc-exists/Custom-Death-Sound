#include "GeodeTabSprite.hpp"
#include <Geode/utils/ColorProvider.hpp>

bool GeodeTabSprite::init(const char* iconFrame, const char* text, float width, bool altColor) {
    if (!CCNode::init())
        return false;

    const CCSize itemSize { width, 28 };
    const CCSize iconSize { 14, 14 };

    this->setContentSize(itemSize);
    this->setAnchorPoint({ .5f, .5f });

    m_deselectedBG = NineSlice::createWithSpriteFrameName("geode.loader/tab-bg.png");
    m_deselectedBG->setScale(.8f);
    m_deselectedBG->setContentSize(itemSize / .8f);
    m_deselectedBG->setColor(geode::ColorProvider::get()->color3b(
        geode::Mod::get()->expandSpriteName("geode.loader/mod-list-tab-deselected-bg")
    ));
    this->addChildAtPosition(m_deselectedBG, Anchor::Center);

    m_selectedBG = NineSlice::createWithSpriteFrameName("geode.loader/tab-bg.png");
    m_selectedBG->setScale(.8f);
    m_selectedBG->setContentSize(itemSize / .8f);
    m_selectedBG->setColor(to3B(geode::ColorProvider::get()->color(
        altColor ?
            "mod-list-tab-selected-bg-alt"_spr :
            "mod-list-tab-selected-bg"_spr
    )));
    this->addChildAtPosition(m_selectedBG, Anchor::Center);

    m_icon = CCSprite::createWithSpriteFrameName(iconFrame);
    limitNodeSize(m_icon, iconSize, 2.5f, .1f);
    this->addChildAtPosition(m_icon, Anchor::Left, ccp(14, 0), false);

    m_label = CCLabelBMFont::create(text, "bigFont.fnt");
    m_label->limitLabelWidth(this->getContentWidth() - 38, std::clamp(width * .0042f, .28f, .48f), .1f);
    m_label->setAnchorPoint({ .5f, .5f });
    this->addChildAtPosition(m_label, Anchor::Left, ccp((itemSize.width - iconSize.width) / 2 + iconSize.width, 0), false);

    return true;
}

GeodeTabSprite* GeodeTabSprite::create(const char* iconFrame, const char* text, float width, bool altColor) {
    auto ret = new GeodeTabSprite();
    if (ret->init(iconFrame, text, width, altColor)) {
        ret->autorelease();
        return ret;
    }
    delete ret;
    return nullptr;
}

void GeodeTabSprite::select(bool selected) {
    m_deselectedBG->setVisible(!selected);
    m_selectedBG->setVisible(selected);
}

void GeodeTabSprite::disable(bool disabled) {
    auto fgColor = disabled ? ccc3(170, 170, 170) : ccc3(255, 255, 255);
    auto bgOpacity = static_cast<GLubyte>(disabled ? 185 : 255);

    m_deselectedBG->setOpacity(bgOpacity);
    m_selectedBG->setOpacity(bgOpacity);
    m_icon->setColor(fgColor);
    m_label->setColor(fgColor);
}