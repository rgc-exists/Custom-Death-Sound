/*
NOTE TO INDEX MODS CHECKING THIS CODE: This repository's main branch is currently showing an UNFINISHED "update" to the mod. There's a good chance it'll never get completed, but it's too late to undo it, so please go to the [original-mod branch](https://github.com/rgc-exists/Custom-Death-Sound/tree/original-mod) to see the version that is currently submitted to Geode.
*/

#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include "nodes/SFXIndexPopup.hpp"

using namespace geode::prelude;

class $modify(MyPauseLayer, PauseLayer) {
public:
    void customSetup() {
        PauseLayer::customSetup();

        auto menu = getChildByID("left-button-menu");
        if (menu) {
            auto sprite = CircleButtonSprite::create(
                CCSprite::createWithSpriteFrameName("edit_eSFXBtn_001.png"),
                CircleBaseColor::DarkAqua,
                CircleBaseSize::Medium
            );

            auto button = CCMenuItemSpriteExtra::create(
                sprite,
                this,
                menu_selector(MyPauseLayer::onSFXLibrary)
            );
            menu->addChild(button);
            menu->updateLayout();
        }
    }

    void onSFXLibrary(CCObject* sender) {
        SFXIndexPopup::create()->show();
    }
};
