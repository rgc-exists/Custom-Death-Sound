#include <Geode/Geode.hpp>
#include "../cocos/CCLayerMultiplexR.hpp"
#include "../../Requests.hpp"

using namespace geode::prelude;

class RequestAdminPopup : public Popup {
protected:
    CCLayerMultiplexR* m_multiplex;
    TextInput* m_verifyEndInput;
public:
    bool init();
    void onVerify(CCObject*);
    void onLogin(CCObject*);
    void onRequest(CCObject*);
    void isLoggedIn(std::function<void(bool)> callback);
    static RequestAdminPopup* create();
};
