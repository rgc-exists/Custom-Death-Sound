#include "RequestAdminPopup.hpp"

bool loggedIn = false;

bool RequestAdminPopup::init() {
    if (!Popup::init(320.f, 240.f, "GJ_square02.png")) return false;

    this->setTitle("Request Admin");

    auto verifyStartLayer = CCLayer::create();
    verifyStartLayer->setPosition({ 0.f, 0.f });
    verifyStartLayer->setContentSize(m_mainLayer->getContentSize());
    verifyStartLayer->setAnchorPoint(m_mainLayer->getAnchorPoint());

    auto verifyEndLayer = CCLayer::create();
    verifyEndLayer->setPosition({ 0.f, 0.f });
    verifyEndLayer->setContentSize(m_mainLayer->getContentSize());
    verifyEndLayer->setAnchorPoint(m_mainLayer->getAnchorPoint());

    auto requestLayer = CCLayer::create();
    requestLayer->setPosition({ 0.f, 0.f });
    requestLayer->setContentSize(m_mainLayer->getContentSize());
    requestLayer->setAnchorPoint(m_mainLayer->getAnchorPoint());

    this->m_multiplex = CCLayerMultiplexR::create({ verifyStartLayer, verifyEndLayer, requestLayer });
    m_multiplex->setContentSize(m_mainLayer->getContentSize());
    m_multiplex->switchTo(0);
    m_mainLayer->addChild(m_multiplex);

    this->isLoggedIn([this](bool valid) {
        loggedIn = valid;
        if (valid) {
            m_multiplex->switchTo(2);
        }
    });

    auto requestNotice = CCLabelBMFont::create(
        "Note: This popup is only meant to be used by actual admins. "
        "Using it without being an admin may result in a website-wide ratelimit. "
        "Use it at your discretion.",
        "bigFont.fnt",
        300.f,
        CCTextAlignment::kCCTextAlignmentCenter
    );
    requestNotice->setScale(0.45f);
    requestNotice->setAnchorPoint({ 0.5f, 1.f });
    requestNotice->setPosition({ 160.f, 200.f });
    requestLayer->addChild(requestNotice);

    auto requestMenu = CCMenu::create();
    requestMenu->setContentSize(requestLayer->getContentSize());
    requestMenu->setPosition({ 0.f, 0.f });
    requestLayer->addChild(requestMenu);

    auto requestButton = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Request"),
        this,
        menu_selector(RequestAdminPopup::onRequest)
    );
    requestButton->setPosition({ 160.f, 60.f });
    requestMenu->addChild(requestButton);

    auto verifyStartNotice = CCLabelBMFont::create(
        "You are not logged in yet. "
        "Please click the button below to log in. ",
        "bigFont.fnt",
        300.f,
        CCTextAlignment::kCCTextAlignmentCenter
    );
    verifyStartNotice->setScale(0.45f);
    verifyStartNotice->setAnchorPoint({ 0.5f, 1.f });
    verifyStartNotice->setPosition({ 160.f, 200.f });
    verifyStartLayer->addChild(verifyStartNotice);

    auto verifyStartMenu = CCMenu::create();
    verifyStartMenu->setContentSize(verifyStartLayer->getContentSize());
    verifyStartMenu->setPosition({ 0.f, 0.f });
    verifyStartLayer->addChild(verifyStartMenu);

    auto verifyBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Get Token"),
        this,
        menu_selector(RequestAdminPopup::onVerify)
    );
    verifyBtn->setPosition({ 160.f, 120.f });
    verifyStartMenu->addChild(verifyBtn);

    auto verifyEndNotice = CCLabelBMFont::create(
        "Please enter in the box below the account ID you got from the website.",
        "bigFont.fnt",
        300.f,
        CCTextAlignment::kCCTextAlignmentCenter
    );
    verifyEndNotice->setScale(0.45f);
    verifyEndNotice->setAnchorPoint({ 0.5f, 1.f });
    verifyEndNotice->setPosition({ 160.f, 200.f });
    verifyEndLayer->addChild(verifyEndNotice);

    this->m_verifyEndInput = TextInput::create(250.f, "Account token...", "bigFont.fnt");
    m_verifyEndInput->setPosition({ 160.f, 120.f });
    verifyEndLayer->addChild(m_verifyEndInput);

    auto verifyEndMenu = CCMenu::create();
    verifyEndMenu->setContentSize(verifyEndLayer->getContentSize());
    verifyEndMenu->setPosition({ 0.f, 0.f });
    verifyEndLayer->addChild(verifyEndMenu);

    auto verifyEndBtn = CCMenuItemSpriteExtra::create(
        ButtonSprite::create("Login"),
        this,
        menu_selector(RequestAdminPopup::onLogin)
    );
    verifyEndBtn->setPosition({ 160.f, 60.f });
    verifyEndMenu->addChild(verifyEndBtn);

    return true;
}

RequestAdminPopup* RequestAdminPopup::create() {
    auto ret = new RequestAdminPopup();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }

    CC_SAFE_DELETE(ret);
    return nullptr;
}

void RequestAdminPopup::onVerify(CCObject* sender) {
    auto serverURL = Mod::get()->getSettingValue<std::string>("server-url");
    CCApplication::get()->openURL(fmt::format("{}/verify", serverURL).c_str());
    this->m_multiplex->switchTo(1);
}

void RequestAdminPopup::onRequest(CCObject* sender) {
    std::string token = Mod::get()->getSettingValue<std::string>("account-token");
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/auth/is-admin";

    if (!token.empty()) {
        url += "?token=" + token;
    }

    auto req = geode::utils::web::WebRequest();
    req.timeout(std::chrono::seconds(15));
    if (!token.empty()) {
        req.header("x-account-token", token);
    }

    auto loadingCircle = LoadingSpinner::create(100.f);
    loadingCircle->setAnchorPoint({ 0.5f, 0.5f });
    loadingCircle->setPosition({ 160.f, 100.f });
    m_multiplex->getLayer(2)->addChild(loadingCircle, 9999, 9999);

    static async::TaskHolder<geode::utils::web::WebResponse> s_adminCheckListener;
    s_adminCheckListener.spawn(
        req.get(url),
        [this, loadingCircle](geode::utils::web::WebResponse value) {
        if (loadingCircle && loadingCircle->getParent()) loadingCircle->removeFromParent();
        bool isAdmin = false;
        std::string errorMsg;
        if (value.ok()) {
            auto jsonOpt = value.json();
            if (jsonOpt.isOk()) {
                auto json = jsonOpt.unwrap();
                if (json.contains("isAdmin") && json["isAdmin"].isBool()) {
                    auto isAdminResult = json["isAdmin"].asBool();
                    if (isAdminResult.isOk()) {
                        isAdmin = isAdminResult.unwrap();
                    } else {
                        errorMsg = "Malformed response from server.";
                    }
                } else {
                    errorMsg = "Malformed response from server.";
                }
            } else {
                errorMsg = value.string().unwrap();
            }
        } else {
            errorMsg = "Request failed with code " + std::to_string(value.code());
        }

        Mod::get()->setSavedValue("is-admin", isAdmin);

        if (!errorMsg.empty()) {
            auto failPopup = FLAlertLayer::create("Admin Check Failed", errorMsg, "OK");
            failPopup->show();
            return;
        }

        if (isAdmin) {
            auto successPopup = FLAlertLayer::create(
                "Request",
                "You are an admin. You may upload or delete sounds and sound packs.",
                "OK"
            );
            successPopup->show();
        } else {
            auto failPopup = FLAlertLayer::create(
                "Not Admin",
                "You are not an admin. Admin features are unavailable.",
                "OK"
            );
            failPopup->show();
        }
    });
}

void RequestAdminPopup::onLogin(CCObject* sender) {
    std::string token = m_verifyEndInput->getString();
    Mod::get()->setSettingValue("account-token", token);

    auto loadingCircle = LoadingSpinner::create(100.f);
    loadingCircle->setAnchorPoint({ 0.5f, 0.5f });
    loadingCircle->setPosition({ 160.f, 100.f });
    m_multiplex->getLayer(1)->addChild(loadingCircle, 9999, 9999);

    isLoggedIn([this, loadingCircle](bool valid) {
        loggedIn = valid;
        if (loadingCircle && loadingCircle->getParent()) loadingCircle->removeFromParent();
        if (valid) {
            m_multiplex->switchTo(2);
        } else {
            m_multiplex->switchTo(0);
        }
    });
}

void RequestAdminPopup::isLoggedIn(std::function<void(bool)> callback) {
    auto accountToken = Mod::get()->getSettingValue<std::string>("account-token");
    auto requests = DSRequest::get();
    if (accountToken == "") {
        callback(false);
        return;
    }
    requests->checkModToken(
        accountToken,
        [callback](const matjson::Value& result) {
            bool valid = result.contains("valid") && result["valid"].isBool() && result["valid"].asBool();
            callback(valid);
        },
        [callback](const matjson::Value&) {
            callback(false);
        }
    );
}
