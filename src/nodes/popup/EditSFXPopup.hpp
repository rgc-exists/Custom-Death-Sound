#pragma once

#include <Geode/Geode.hpp>
#include "../cell/SFXCell.hpp"

using namespace geode::prelude;

class EditSFXPopup : public geode::Popup {
public:
    static EditSFXPopup* create(SFXCell* cell);
    bool init(SFXCell* cell);

private:
    SFXCell* m_cell = nullptr;
    TextInput* m_nameInput = nullptr;
    TextInput* m_tagsInput = nullptr;
    void onSave(CCObject*);
};
