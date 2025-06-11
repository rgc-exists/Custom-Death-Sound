#include <Geode/Geode.hpp>
#include "Border.hpp"

using namespace geode::prelude;

deathsounds::Border* deathsounds::Border::create(CCNode* node, const ccColor4B& backgroundColor, const CCSize& size, const CCPoint& padding) {
    deathsounds::Border* instance = new deathsounds::Border(padding);

    if (instance->init(node, backgroundColor, size)) {
        instance->autorelease();
        return instance;
    }

    delete instance;
    return nullptr;
}

deathsounds::Border::Border(const CCPoint& padding) : m_padding({ padding.x, padding.y, padding.x, padding.y }) { }

bool deathsounds::Border::init(const ccColor4B& backgroundColor, const CCSize& size) {
    return this->init(nullptr, backgroundColor, size);
}

bool deathsounds::Border::init(CCNode* node, const ccColor4B& backgroundColor, const CCSize& size) {
    if (!this->initWithColor(backgroundColor)) {
        return false;
    }

    CCScale9Sprite* border = CCScale9Sprite::create("sfxListBorder.png"_spr);
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

void deathsounds::Border::setPadding(const CCPoint& padding) {
    this->setPadding(padding.x, padding.y);
}

void deathsounds::Border::setPadding(float x, float y) {
    this->setPaddingX(x);
    this->setPaddingY(y);
}

void deathsounds::Border::setPadding(float padding) {
    this->setPadding(padding, padding);
}

void deathsounds::Border::setPaddingX(float x) {
    this->setPaddingLeft(x);
    this->setPaddingRight(x);
}

deathsounds::Border::Padding deathsounds::Border::getPadding() {
    return m_padding;
}

float deathsounds::Border::getPaddingX() {
    return (m_padding.left + m_padding.right) / 2;
}

void deathsounds::Border::setPaddingY(float y) {
    this->setPaddingTop(y);
    this->setPaddingBottom(y);
}

float deathsounds::Border::getPaddingY() {
    return (m_padding.top + m_padding.bottom) / 2;
}

void deathsounds::Border::setPaddingTop(float top) {
    m_padding.top = top;

    this->updatePadding();
}

float deathsounds::Border::getPaddingTop() {
    return m_padding.top;
}

void deathsounds::Border::setPaddingRight(float right) {
    m_padding.right = right;

    this->updatePadding();
}

float deathsounds::Border::getPaddingRight() {
    return m_padding.right;
}

void deathsounds::Border::setPaddingBottom(float bottom) {
    m_padding.bottom = bottom;

    this->updatePadding();
}

float deathsounds::Border::getPaddingBottom() {
    return m_padding.bottom;
}

void deathsounds::Border::setPaddingLeft(float left) {
    m_padding.left = left;

    this->updatePadding();
}

float deathsounds::Border::getPaddingLeft() {
    return m_padding.left;
}

void deathsounds::Border::setBackgroundColor(const ccColor4B& color) {
    this->setColor({ color.r, color.g, color.b });
    this->setOpacity(color.a);
}

ccColor4B deathsounds::Border::getBackgroundColor() {
    return { _displayedColor.r, _displayedColor.g, _displayedColor.b, _displayedOpacity };
}

void deathsounds::Border::setNode(CCNode* node) {
    CCNode* content = this->getChildByID("border_content"_spr);

    // Can't assume an ID as the node is a user input and may have its ID changed
    if (CCNode* oldNode = cocos::getChild<CCNode>(content, 0)) {
        // Not going to mess with releasing the node, I'll leave that to the user
        oldNode->removeFromParent();
    }

    content->addChild(node);

    this->updatePadding();
}

CCNode* deathsounds::Border::getNode() {
    if (CCNode* node = cocos::getChild<CCNode>(this->getChildByID("border_content"_spr), 0)) {
        return node;
    } else {
        return nullptr;
    }
}

void deathsounds::Border::setSize(const CCSize& size) {
    this->setContentSize(size);
    this->getChildByID("border_sprite"_spr)->setContentSize(size);
    this->getChildByID("border_content"_spr)->setContentSize(size);
    this->updatePadding();
}

void deathsounds::Border::updatePadding() {
    if (CCNode* node = this->getNode()) {
        CCSize size = this->getContentSize();

        node->setAnchorPoint({ 0, 0 });
        node->setPosition({ m_padding.left, m_padding.bottom });
        node->setContentSize(size - ccp(this->getPaddingX(), this->getPaddingY()) * 2);
    }
}