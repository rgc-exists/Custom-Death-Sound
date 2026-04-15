#pragma once

#include <Geode/Geode.hpp>
#include "../cell/SFXPackCell.hpp"

using namespace geode::prelude;

class EditSoundPackPopup : public geode::Popup {
public:
    static EditSoundPackPopup* create(SFXPackCell* cell);
    bool init(SFXPackCell* cell);

private:
    SFXPackCell* m_cell = nullptr;
    CCTextInputNode* m_nameInput = nullptr;
    CCTextInputNode* m_tracksInput = nullptr;
    void onSave(CCObject*);
};
