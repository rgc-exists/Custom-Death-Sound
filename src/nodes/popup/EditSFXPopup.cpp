#include "EditSFXPopup.hpp"
#include "../cell/SFXCell.hpp"
#include <Geode/loader/Mod.hpp>

bool EditSFXPopup::init(SFXCell* cell) {
    if (!geode::Popup::init(320.f, 240.f, "GJ_square02.png")) return false;
    this->setTitle("Edit SFX");
    m_cell = cell;

    m_nameInput = TextInput::create(250.f, "Name...", "bigFont.fnt");
    m_nameInput->setString(cell->getName().c_str());
    m_nameInput->setPosition({ 160.f, 180.f });
    this->addChild(m_nameInput);

    // m_tagsInput = TextInput::create();
    // std::string tags;
    // const auto& tagVec = cell->getTags();
    // for (size_t i = 0; i < tagVec.size(); ++i) {
    //     tags += tagVec[i];
    //     if (i + 1 < tagVec.size()) tags += ", ";
    // }
    // m_tagsInput->setString(tags.c_str());
    // m_tagsInput->setPosition({160.f, 130.f});
    // this->addChild(m_tagsInput);

    auto saveBtn = CCMenuItemSpriteExtra::create(ButtonSprite::create("Save"), this, menu_selector(EditSFXPopup::onSave));
    auto menu = CCMenu::createWithItem(saveBtn);
    menu->setPosition({160.f, 60.f});
    this->addChild(menu);

    return true;
}

EditSFXPopup* EditSFXPopup::create(SFXCell* cell) {
    auto ret = new EditSFXPopup();
    if (ret && ret->init(cell)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void EditSFXPopup::onSave(CCObject*) {
    m_cell->setName(m_nameInput->getString());
    std::vector<std::string> tags;
    std::string tagsStr = m_tagsInput->getString();
    std::stringstream ss(tagsStr);
    std::string tag;
    while (std::getline(ss, tag, ',')) {
        tag.erase(0, tag.find_first_not_of(" \t"));
        tag.erase(tag.find_last_not_of(" \t") + 1);
        if (!tag.empty()) tags.push_back(tag);
    }
    m_cell->setTags(tags);
    this->onClose(nullptr);
}
