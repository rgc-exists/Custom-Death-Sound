#include "UploadSoundPopup.hpp"

bool UploadSoundPopup::init() {
    if (!Popup::init(280.f, 230.f)) return false;

    return true;
}

UploadSoundPopup* UploadSoundPopup::create() {
    auto ret = new UploadSoundPopup();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}
