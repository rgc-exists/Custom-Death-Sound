#include "EditSoundPackPopup.hpp"
#include "../cell/SFXPackCell.hpp"

bool EditSoundPackPopup::init(SFXPackCell* cell) {
    if (!geode::Popup::init(320.f, 240.f, "GJ_square02.png")) return false;
    this->setTitle("Edit Sound Pack");
    m_cell = cell;

    float y = 180.f;
    m_nameInput = CCTextInputNode::create(250.f, 30.f, "Pack Name", "bigFont.fnt");
    m_nameInput->setString(cell->getName().c_str());
    m_nameInput->setPosition({160.f, y});
    this->addChild(m_nameInput);
    y -= 50.f;

    m_tracksInput = CCTextInputNode::create(250.f, 30.f, "Track IDs (comma separated)", "bigFont.fnt");
    std::string tracks;
    const auto& soundIds = cell->getSoundIds();
    for (size_t i = 0; i < soundIds.size(); ++i) {
        tracks += soundIds[i];
        if (i + 1 < soundIds.size()) tracks += ", ";
    }
    m_tracksInput->setString(tracks.c_str());
    m_tracksInput->setPosition({160.f, y});
    this->addChild(m_tracksInput);
    y -= 50.f;

    auto saveBtn = CCMenuItemSpriteExtra::create(ButtonSprite::create("Save"), this, menu_selector(EditSoundPackPopup::onSave));
    auto menu = CCMenu::createWithItem(saveBtn);
    menu->setPosition({160.f, y});
    this->addChild(menu);

    return true;
}

EditSoundPackPopup* EditSoundPackPopup::create(SFXPackCell* cell) {
    auto ret = new EditSoundPackPopup();
    if (ret && ret->init(cell)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void EditSoundPackPopup::onSave(CCObject*) {
    m_cell->setName(m_nameInput->getString());
    std::vector<std::string> ids;
    std::string tracksStr = m_tracksInput->getString();
    std::stringstream ss(tracksStr);
    std::string track;
    while (std::getline(ss, track, ',')) {
        track.erase(0, track.find_first_not_of(" \t"));
        track.erase(track.find_last_not_of(" \t") + 1);
        if (!track.empty()) ids.push_back(track);
    }
    m_cell->setSoundIds(ids);
    this->onClose(nullptr);
}
