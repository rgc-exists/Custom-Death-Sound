#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class CCLayerMultiplexR : public CCLayer {

public:
    static CCLayerMultiplexR* create(std::initializer_list<CCLayer*> layers);
    bool init(std::initializer_list<CCLayer*> layers);
    void switchTo(unsigned int index);
    CCLayer* getLayer(size_t index) const;

private:
    std::vector<CCLayer*> m_layers;
    unsigned int m_activeIndex = 0;
};
