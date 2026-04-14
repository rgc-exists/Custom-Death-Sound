#include "CCLayerMultiplexR.hpp"

CCLayerMultiplexR* CCLayerMultiplexR::create(std::initializer_list<CCLayer*> layers) {
    auto ret = new CCLayerMultiplexR();
    if (ret && ret->init(layers)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

bool CCLayerMultiplexR::init(std::initializer_list<CCLayer*> layers) {
    if (!CCLayer::init() || layers.size() == 0) {
        return false;
    }

    m_layers.reserve(layers.size());

    for (auto* layer : layers) {
        if (!layer) {
            continue;
        }

        m_layers.push_back(layer);
        layer->setAnchorPoint({ 0.f, 0.f });
        layer->setPosition({ 0.f, 0.f });
        layer->setVisible(false);
        this->addChild(layer);
    }

    if (m_layers.empty()) {
        return false;
    }

    m_activeIndex = 0;
    m_layers[m_activeIndex]->setVisible(true);
    return true;
}

void CCLayerMultiplexR::switchTo(unsigned int index) {
    if (index >= m_layers.size() || index == m_activeIndex) {
        return;
    }

    m_layers[m_activeIndex]->setVisible(false);
    m_activeIndex = index;
    m_layers[m_activeIndex]->setVisible(true);
}

CCLayer* CCLayerMultiplexR::getLayer(size_t index) const {
    if (index < m_layers.size()) {
        return m_layers[index];
    }
    return nullptr;
}
