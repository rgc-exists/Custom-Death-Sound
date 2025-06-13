#include "SFXCell.hpp"

std::string formatDate(int32_t millis) {
    using namespace std::chrono;
    std::time_t seconds = static_cast<std::time_t>(millis);
    std::tm local_tm = fmt::localtime(seconds);
    return fmt::format("{:%Y-%m-%d}", local_tm);
}

namespace deathsounds {
    bool SFXCell::init(int index, std::string id, std::string name, int downloads, int32_t createdAt/*, int likes, int dislikes*/) {
        if (!CCLayer::init()) {
            return false;
        }

        setMouseEnabled(true);
        setTouchEnabled(true);

        setContentSize({ 340.f, 80.f });

        ccColor3B bgColor = (index % 2 == 0) ? ccc3(75, 75, 75) : ccc3(50, 50, 50);
        auto layerBG = CCLayerColor::create(ccc4(bgColor.r, bgColor.g, bgColor.b, 255));
        layerBG->setContentSize(getContentSize());
        addChild(layerBG);

        auto widget = CCLayer::create();
        widget->setContentSize({ getContentWidth() * 0.8f, getContentHeight() - 20.f });
        widget->setPosition({ getContentWidth() * 0.1f, 10.f });
        addChild(widget);

        auto menu = CCMenu::create();
        menu->setPosition({ 0.f, 0.f });
        menu->setContentSize(widget->getContentSize());
        widget->addChild(menu, 500);
        
        auto widgetBG = CCScale9Sprite::create("GJ_square01.png");
        widgetBG->setContentSize(widget->getContentSize());
        widgetBG->setAnchorPoint({ 0.f, 0.f });
        widget->addChild(widgetBG);

        /*
        auto sfxToggle = CCMenuItemExt::createToggler(
            CCSprite::createWithSpriteFrameName("GJ_stopMusicBtn_001.png"),
            CCSprite::createWithSpriteFrameName("GJ_playMusicBtn_001.png"),
            [&](CCMenuItemToggler* toggler) {
                auto fmod = FMODAudioEngine::sharedEngine();
                if (toggler->isOn()) {
                    fmod->stopAllEffects();
                } else {
                    fmod->playEffect("shop.mp3"); // idk here lmao
                    // toggler->toggle(false);
                }
            }
        );
        sfxToggle->setPosition({ menu->getContentWidth() - 30.f, menu->getContentHeight() / 2 });
        menu->addChild(sfxToggle);
        */

        std::string displayName = name;
        if (displayName.size() > 25) {
            displayName = displayName.substr(0, 25) + "...";
        }
        auto nameLabel = CCLabelBMFont::create(displayName.c_str(), "bigFont.fnt");
        nameLabel->setAnchorPoint({ 0.f, 1.f });
        nameLabel->setScale(0.5f);
        nameLabel->setPosition({ 10.f, widget->getContentHeight() - 10.f });
        widget->addChild(nameLabel);

        auto downloadsSprite = CCSprite::createWithSpriteFrameName("GJ_sDownloadIcon_001.png");
        downloadsSprite->setPosition({ 20.f, 20.f });
        widget->addChild(downloadsSprite);

        auto formatDownloads = [](int downloads) -> std::string {
            char buf[16];
            if (downloads >= 1000000000)
            std::snprintf(buf, sizeof(buf), "%.1fB", downloads / 1000000000.0);
            else if (downloads >= 1000000)
            std::snprintf(buf, sizeof(buf), "%.1fM", downloads / 1000000.0);
            else if (downloads >= 1000)
            std::snprintf(buf, sizeof(buf), "%.1fK", downloads / 1000.0);
            else
            std::snprintf(buf, sizeof(buf), "%d", downloads);
            std::string s(buf);
            if (s.find('.') != std::string::npos) {
            s.erase(s.find_last_not_of('0') + 1, std::string::npos);
            if (s.back() == '.') s.pop_back();
            }
            return s;
        };

        auto downloadsText = CCLabelBMFont::create(formatDownloads(downloads).c_str(), "bigFont.fnt");
        downloadsText->setAnchorPoint({ 0.f, 0.5f });
        downloadsText->setScale(0.4f);
        downloadsText->setPosition({ 30.f, 20.f });
        widget->addChild(downloadsText);

        /*CCSprite* likesSprite;
        if ((likes - dislikes) >= 0) {
            likesSprite = CCSprite::createWithSpriteFrameName("GJ_sLikeIcon_001.png");
        } else {
            likesSprite = CCSprite::createWithSpriteFrameName("GJ_dislikesIcon_001.png");
            likesSprite->setScale(0.6f);
        }
        likesSprite->setPosition({ 90.f, 20.f });
        widget->addChild(likesSprite);

        auto likesText = CCLabelBMFont::create(std::to_string(likes - dislikes).c_str(), "bigFont.fnt");
        likesText->setAnchorPoint({ 0.f, 0.5f });
        likesText->setScale(0.4f);
        likesText->setPosition({ 100.f, 20.f });
        widget->addChild(likesText);*/

        auto infoButton = InfoAlertButton::create(
            displayName,
            fmt::format("<cb>Name (full):</c> {}\n<cy>Uploaded:</c> {}\n<cg>Downloads:</c> {}", 
                name, formatDate(createdAt), downloads),
            0.5f
        );
        infoButton->setPosition(menu->getContentSize() - 10.f);
        menu->addChild(infoButton);

        return true;
    }

    SFXCell* SFXCell::create(int index, std::string id, std::string name, int downloads, int32_t createdAt/*, int likes, int dislikes*/) {
        auto ret = new SFXCell();
        if (ret && ret->init(index, id, name, downloads, createdAt/*, likes, dislikes*/)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }
}
