#include <Geode/Geode.hpp>

using namespace geode::prelude;

std::string formatDate(int64_t millis) {
    std::chrono::system_clock::time_point tp = std::chrono::system_clock::time_point(std::chrono::milliseconds(1749500909106));
    return fmt::format("{:%Y-%m-%d}\n", tp);
}

namespace deathsounds {
    class SFXCell : public CCLayer {
    public:
        bool init(int index, std::string id, std::string name, int downloads, int createdAt) {
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

            /*auto sfxToggle = CCMenuItemExt::createToggler(
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
            menu->addChild(sfxToggle);*/

            auto nameLabel = CCLabelBMFont::create(name.c_str(), "bigFont.fnt");
            nameLabel->setAnchorPoint({ 0.f, 1.f });
            nameLabel->setScale(0.5f);
            nameLabel->setPosition({ 10.f, widget->getContentHeight() - 10.f });
            widget->addChild(nameLabel);

            auto downloadsSprite = CCSprite::createWithSpriteFrameName("GJ_sDownloadIcon_001.png");
            downloadsSprite->setPosition({ 20.f, 20.f });
            widget->addChild(downloadsSprite);

            auto downloadsText = CCCounterLabel::create(downloads, "bigFont.fnt", FormatterType::Integer);
            downloadsText->setAnchorPoint({ 0.f, 0.5f });
            downloadsText->setScale(0.4f);
            downloadsText->setPosition({ 30.f, 20.f });
            widget->addChild(downloadsText);

            auto infoButton = InfoAlertButton::create(name, fmt::format("<cy>Uploaded:</c> {}\n<cg>Downloads:</c> {}", formatDate(createdAt), downloads), 0.5f);
            infoButton->setPosition(menu->getContentSize() - 10.f);
            menu->addChild(infoButton);

            return true;
        }

        static SFXCell* create(int index, std::string id, std::string name, int downloads, int createdAt) {
            auto ret = new SFXCell();
            if (ret && ret->init(index, id, name, downloads, createdAt)) {
                ret->autorelease();
                return ret;
            }
            CC_SAFE_DELETE(ret);
            return nullptr;
        }
    };
};
