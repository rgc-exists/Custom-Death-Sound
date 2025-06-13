#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace deathsounds {
    class SFXCell : public CCLayer {
    public:
        bool init(int index, std::string id, std::string name, int downloads, int32_t createdAt/*, int likes, int dislikes*/);
        static SFXCell* create(int index, std::string id, std::string name, int downloads, int32_t createdAt/*, int likes, int dislikes*/);
    };
}
