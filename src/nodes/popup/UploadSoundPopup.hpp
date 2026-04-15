#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class UploadSoundPopup : public Popup {
private:
    bool init();

public:
    static UploadSoundPopup* create();
};
