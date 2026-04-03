#include <Geode/Geode.hpp>

using namespace geode::prelude;

class GeodeTabSprite : public CCNode {
protected:
    NineSlice* m_deselectedBG;
    NineSlice* m_selectedBG;
    CCSprite* m_icon;
    CCLabelBMFont* m_label;

    bool init(const char* iconFrame, const char* text, float width, bool altColor);

public:
    static GeodeTabSprite* create(const char* iconFrame, const char* text, float width, bool altColor = false);

    void select(bool selected);
    void disable(bool disabled);
};