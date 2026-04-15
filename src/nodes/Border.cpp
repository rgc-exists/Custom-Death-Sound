#include <Geode/Geode.hpp>
#include "Border.hpp"

using namespace geode::prelude;

DSBorder* DSBorder::create(CCNode* node, const ccColor4B& backgroundColor, const CCSize& size, const CCPoint& padding) {
    DSBorder* instance = new DSBorder(padding);

    if (instance->init(node, backgroundColor, size)) {
        instance->autorelease();
        return instance;
    }

    delete instance;
    return nullptr;
}

DSBorder::DSBorder(const CCPoint& padding) : m_padding({ padding.x, padding.y, padding.x, padding.y }) { }

bool DSBorder::init(const ccColor4B& backgroundColor, const CCSize& size) {
    return this->init(nullptr, backgroundColor, size);
}

bool DSBorder::init(CCNode* node, const ccColor4B& backgroundColor, const CCSize& size) {
    if (!this->initWithColor(backgroundColor)) {
        return false;
    }

    CCScale9Sprite* border = CCScale9Sprite::create("sfxListDSBorder.png"_spr);
    CCLayer* content = CCLayer::create();

    border->setID("border_sprite"_spr);
    border->setAnchorPoint({ 0, 0 });
    border->setPosition({ 0, 0 });
    border->setZOrder(1);
    content->setID("border_content"_spr);
    content->setContentSize(size);
    this->addChild(border);
    this->addChild(content);

    if (node != nullptr) {
        this->setNode(node);
    }

    this->setSize(size);

    return true;
}

void DSBorder::setPadding(const CCPoint& padding) {
    this->setPadding(padding.x, padding.y);
}

void DSBorder::setPadding(float x, float y) {
    this->setPaddingX(x);
    this->setPaddingY(y);
}

void DSBorder::setPadding(float padding) {
    this->setPadding(padding, padding);
}

void DSBorder::setPaddingX(float x) {
    this->setPaddingLeft(x);
    this->setPaddingRight(x);
}

DSBorder::Padding DSBorder::getPadding() {
    return m_padding;
}

float DSBorder::getPaddingX() {
    return (m_padding.left + m_padding.right) / 2;
}

void DSBorder::setPaddingY(float y) {
    this->setPaddingTop(y);
    this->setPaddingBottom(y);
}

float DSBorder::getPaddingY() {
    return (m_padding.top + m_padding.bottom) / 2;
}

void DSBorder::setPaddingTop(float top) {
    m_padding.top = top;

    this->updatePadding();
}

float DSBorder::getPaddingTop() {
    return m_padding.top;
}

void DSBorder::setPaddingRight(float right) {
    m_padding.right = right;

    this->updatePadding();
}

float DSBorder::getPaddingRight() {
    return m_padding.right;
}

void DSBorder::setPaddingBottom(float bottom) {
    m_padding.bottom = bottom;

    this->updatePadding();
}

float DSBorder::getPaddingBottom() {
    return m_padding.bottom;
}

void DSBorder::setPaddingLeft(float left) {
    m_padding.left = left;

    this->updatePadding();
}

float DSBorder::getPaddingLeft() {
    return m_padding.left;
}

void DSBorder::setBackgroundColor(const ccColor4B& color) {
    this->setColor({ color.r, color.g, color.b });
    this->setOpacity(color.a);
}

ccColor4B DSBorder::getBackgroundColor() {
    return { _displayedColor.r, _displayedColor.g, _displayedColor.b, _displayedOpacity };
}

void DSBorder::setNode(CCNode* node) {
    CCNode* content = this->getChildByID("border_content"_spr);

    if (CCNode* oldNode = content->getChildByIndex(0)) {
        oldNode->removeFromParent();
    }

    content->addChild(node);

    this->updatePadding();
}

CCNode* DSBorder::getNode() {
    if (auto border = getChildByID("border_content"_spr)) {
        if (CCNode* node = border->getChildByType<CCNode>(0)) {
            return node;
        } else {
            return nullptr;
        }
    } else {
        return nullptr;
    }
}

void DSBorder::setSize(const CCSize& size) {
    this->setContentSize(size);
    this->getChildByID("border_sprite"_spr)->setContentSize(size);
    this->getChildByID("border_content"_spr)->setContentSize(size);
    this->updatePadding();
}

void DSBorder::updatePadding() {
    if (CCNode* node = this->getNode()) {
        CCSize size = this->getContentSize();

        node->setAnchorPoint({ 0, 0 });
        node->setPosition({ m_padding.left, m_padding.bottom });
        node->setContentSize(size - ccp(this->getPaddingX(), this->getPaddingY()) * 2);
    }
}