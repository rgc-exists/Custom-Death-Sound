#include "SFXIndexPopup.hpp"
#include "Geode/utils/file.hpp"
#include "SearchFilterPopup.hpp"
#include "Geode/ui/GeodeUI.hpp"
#include "../cell/SFXCell.hpp"
#include "../cell/SFXPackCell.hpp"
#include "../../Requests.hpp"
#include "../../Utils.hpp"
#include <Geode/ui/BasedButton.hpp>
#include <Geode/ui/BasedButtonSprite.hpp>

using namespace geode::prelude;

std::string trim(std::string value) {
    auto isSpace = [](unsigned char c) { return std::isspace(c) != 0; };
    auto begin = std::find_if_not(value.begin(), value.end(), isSpace);

    if (begin == value.end()) {
        return "";
    }

    auto end = std::find_if_not(value.rbegin(), value.rend(), isSpace).base();
    return std::string(begin, end);
}

static bool fileExists(const std::string& path) {
    std::ifstream f(path);
    return f.good();
}

static bool readFileString(const std::string& path, std::string& out) {
    std::ifstream f(path, std::ios::in | std::ios::binary);
    if (!f) return false;
    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    f.seekg(0, std::ios::beg);
    out.resize(size);
    f.read(&out[0], size);
    return true;
}

SFXIndexPopup::TabWidgets& SFXIndexPopup::widgetsForTab(Tab tab) {
    switch (tab) {
        case Tab::Downloaded:
            return m_downloadedWidgets;
        case Tab::OnlineSounds:
            return m_onlineWidgets;
        case Tab::SoundPacks:
            return m_packWidgets;
    }

    return m_onlineWidgets;
}

SFXIndexPopup::TabWidgets& SFXIndexPopup::activeWidgets() {
    return widgetsForTab(m_activeTab);
}

void SFXIndexPopup::setTabLoading(TabWidgets& widgets) {
    widgets.loading->setVisible(true);
    widgets.clipping->setVisible(true);
    widgets.border->setVisible(true);
    widgets.error->setVisible(false);
    if (widgets.errorMenu) {
        widgets.errorMenu->setVisible(false);
    }
    if (m_pageLabel) {
        m_pageLabel->setVisible(true);
    }
    if (widgets.infoButton) {
        widgets.infoButton->setVisible(false);
    }
}

void SFXIndexPopup::setTabContentVisible(TabWidgets& widgets, bool showPagination) {
    widgets.loading->setVisible(false);
    widgets.error->setVisible(false);
    if (widgets.errorMenu) {
        widgets.errorMenu->setVisible(false);
    }
    widgets.clipping->setVisible(true);
    widgets.border->setVisible(true);
    setPaginationVisible(showPagination);
    if (m_pageLabel) {
        m_pageLabel->setVisible(true);
    }
    if (widgets.infoButton) {
        widgets.infoButton->setVisible(false);
    }
}

void SFXIndexPopup::setTabError(TabWidgets& widgets, char const* text, bool showResetToFirstPage) {
    widgets.loading->setVisible(false);
    widgets.error->setString(text);
    widgets.lastErrorCode = text ? text : "";
    widgets.error->setVisible(true);
    if (widgets.errorMenu) {
        widgets.errorMenu->setVisible(showResetToFirstPage);
    }
    clearList(widgets);
    widgets.clipping->setVisible(true);
    widgets.border->setVisible(true);
    setPaginationVisible(false);
    if (m_pageLabel) {
        m_pageLabel->setVisible(false);
    }
    if (widgets.infoButton) {
        widgets.infoButton->setVisible(true);
    }

    if (widgets.infoButton) {
        widgets.infoButton->removeFromParent();
        widgets.infoButton = nullptr;
    }

    if (text && std::strcmp(text, "0") != 0) {
        auto infoTabSprite = GeodeTabSprite::create("GJ_infoIcon_001.png", "Info", 96.f);
        auto infoButton = CCMenuItemSpriteExtra::create(
            infoTabSprite,
            this,
            menu_selector(SFXIndexPopup::onInfoButton)
        );
        float yOffset = -50.f;
        if (std::string(text).find("404") != std::string::npos) {
            yOffset = -90.f;
        }
        infoButton->setPosition({
            widgets.layer->getContentSize().width / 2,
            widgets.error->getPositionY() + yOffset
        });
        auto infoMenu = CCMenu::create();
        infoMenu->setPosition({0.f, 0.f});
        infoMenu->addChild(infoButton);
        widgets.layer->addChild(infoMenu, 100);
        widgets.infoButton = infoButton;
    }
}


void SFXIndexPopup::setPaginationVisible(bool visible) {
    if (m_prevPageBtn) {
        m_prevPageBtn->setVisible(visible);
    }
    if (m_nextPageBtn) {
        m_nextPageBtn->setVisible(visible);
    }
}

void SFXIndexPopup::setPageText(std::string const& text) {
    if (m_pageLabel) {
        m_pageLabel->setString(text.c_str());
        m_pageLabel->setVisible(true);
    }
}

int& SFXIndexPopup::pageForTab(Tab tab) {
    switch (tab) {
        case Tab::Downloaded:
            return m_downloadedPage;
        case Tab::OnlineSounds:
            return m_onlinePage;
        case Tab::SoundPacks:
            return m_packPage;
    }

    return m_downloadedPage;
}

std::string& SFXIndexPopup::queryForTab(Tab tab) {
    if (tab == Tab::OnlineSounds) {
        return m_onlineSearchQuery;
    }
    return m_packSearchQuery;
}

bool& SFXIndexPopup::recentForTab(Tab tab) {
    if (tab == Tab::OnlineSounds) {
        return m_onlineRecent;
    }
    return m_packRecent;
}

bool& SFXIndexPopup::inUseForTab(Tab tab) {
    if (tab == Tab::OnlineSounds) {
        return m_onlineInUse;
    }
    return m_packInUse;
}

bool SFXIndexPopup::filtersSetForTab(Tab tab) const {
    if (tab == Tab::OnlineSounds) {
        return !m_onlineSearchQuery.empty() || m_onlineRecent || m_onlineInUse;
    }
    if (tab == Tab::SoundPacks) {
        return !m_packSearchQuery.empty() || m_packRecent || m_packInUse;
    }
    return false;
}

void SFXIndexPopup::populateTabRows(TabWidgets& widgets, std::function<void(int&, float&)> const& appendRow) {
    clearList(widgets);

    float totalHeight = 0.f;
    int index = 0;
    appendRow(index, totalHeight);

    widgets.list->m_contentLayer->updateLayout();
    widgets.list->scrollToTop();
    widgets.border->setVisible(true);
}

SFXIndexPopup::TabWidgets SFXIndexPopup::createTabWidgets() {
    TabWidgets widgets;
    constexpr float kTabContentYOffset = -18.f;
    widgets.layer = CCLayer::create();
    widgets.layer->setContentSize(m_mainLayer->getContentSize());
    widgets.layer->setPosition({ m_mainLayer->getContentSize().width / 2, (m_mainLayer->getContentSize().height / 2) + kTabContentYOffset });

    widgets.loading = LoadingSpinner::create(100.f);
    widgets.layer->addChildAtPosition(widgets.loading, Anchor::Center);

    widgets.list = ScrollLayer::create({ 340.f, 220.f });

    auto columnLayout = ColumnLayout::create();
    columnLayout->setAxisReverse(true)
        ->setAutoGrowAxis(widgets.list->getContentHeight())
        ->setCrossAxisOverflow(false)
        ->setAxisAlignment(AxisAlignment::Center)
        ->setGap(0.f);
    widgets.list->m_contentLayer->setLayout(columnLayout);

    widgets.clipping = CCClippingNode::create();
    widgets.clipping->setContentSize({ 340.f, 220.f });
    widgets.clipping->setAnchorPoint({ 0.f, 0.f });
    widgets.clipping->setPosition({ 50.f, 27.f });

    auto stencil = CCLayerColor::create(ccc4(255, 255, 255, 255), 340.f, 220.f);
    stencil->setAnchorPoint({ 0.f, 0.f });
    widgets.clipping->setStencil(stencil);

    widgets.list->setPosition({ 0.f, 0.f });
    widgets.clipping->addChild(widgets.list);

    widgets.border = DSBorder::create(widgets.list, { 75, 75, 75, 255 }, { 340.f, 220.f });
    widgets.border->setPosition({ 0.f, 0.f });
    widgets.border->setVisible(false);
    widgets.clipping->addChild(widgets.border);
    widgets.layer->addChild(widgets.clipping);
    widgets.loading->setZOrder(10);

    widgets.error = CCLabelBMFont::create("", "bigFont.fnt", 350.f);
    widgets.error->setPosition(widgets.layer->getContentSize() / 2);
    widgets.error->setScale(0.5f);
    widgets.error->setVisible(false);
    widgets.layer->addChild(widgets.error);

    widgets.errorMenu = CCMenu::create();
    widgets.errorMenu->setPosition({ 0.f, 0.f });
    widgets.errorMenu->setVisible(false);
    widgets.layer->addChild(widgets.errorMenu);

    auto resetSprite = ButtonSprite::create("Return to First Page", "goldFont.fnt", "GJ_button_01.png", 0.7f);
    widgets.resetToFirstPageBtn = CCMenuItemSpriteExtra::create(
        resetSprite,
        this,
        menu_selector(SFXIndexPopup::resetToFirstPage)
    );
    widgets.resetToFirstPageBtn->setPosition({ widgets.layer->getContentSize().width / 2, widgets.layer->getContentSize().height / 2 - 28.f });
    widgets.errorMenu->addChild(widgets.resetToFirstPageBtn);

    widgets.infoButton = nullptr;
        widgets.lastErrorCode = "";
        return widgets;
}

void SFXIndexPopup::onInfoButton(CCObject*) {
    auto& widgets = widgetsForTab(m_activeTab);
    std::string code = widgets.lastErrorCode;
    size_t pos = code.find_first_of("-0123456789");
    if (pos != std::string::npos) {
        size_t end = pos;
        if (code[end] == '-') ++end;
        while (end < code.size() && isdigit(code[end])) ++end;
        code = code.substr(pos, end - pos);
    }
    log::info("Info button pressed, error code: '{}'", code);
    auto jsonPath = Mod::get()->getResourcesDir() / "curl-error-desc.json";
    auto result = file::readJson(jsonPath);
    std::string title = "Unknown", desc = "No description.";
    if (result) {
        auto root = result.unwrap();
        std::vector<std::string> keys;
        if (root.isObject()) {
            for (auto it = root.begin(); it != root.end(); ++it) {
                auto keyOpt = it->getKey();
                if (keyOpt) keys.push_back(*keyOpt);
            }
        }
        log::debug("Available error code keys in JSON: [{}]", fmt::join(keys, ", "));
        if (root.contains(code)) {
            auto entry = root[code];
            if (entry.contains("title")) title = entry["title"].asString().unwrapOr("Unknown Error");
            if (entry.contains("description")) desc = entry["description"].asString().unwrapOr(
                "The error couldn't be found. "
                "You may find information on **negative errors** [here](https://curl.se/libcurl/c/libcurl-errors.html), "
                "and **positive (3-digit) errors** [here](https://developer.mozilla.org/en-US/docs/Web/HTTP/Reference/Status). "
                "If you need any assistance, feel free to contact us (the mod developers) on "
                "[GitHub](https://github.com/rgc-exists/Custom-Death-Sound). Sorry for the inconvenience."
            );
            if (entry.contains("credit") && entry["credit"].isObject()) {
                auto credit = entry["credit"];
                std::string author = credit.contains("author") ? credit["author"].asString().unwrapOr("Unknown Author") : "";
                std::string link = credit.contains("link") ? credit["link"].asString().unwrapOr("https://example.com") : "";
                if (!author.empty() && !link.empty()) {
                    desc += "\n\nDescription by [" + author + "](" + link + ").";
                } else if (!author.empty()) {
                    desc += "\n\nDescription by [" + author + "](" + link + ").";
                }
            }
        }
    } else {
        log::warn("Failed to load or parse curl-error-desc.json");
    }
    auto popupTitle = fmt::format("Error {}: {}", code, title);
    MDPopup::create(popupTitle, desc, "OK")->show();
}

bool SFXIndexPopup::init(bool settingsEnabled) {
        constexpr float kTabButtonY = 248.f;

    if (!Popup::init(440.f, 290.f, "GJ_square02.png")) return false;

    this->setTitle("Death SFX Index");
    this->m_title->setPositionY(275.f);

    auto menu = CCMenu::create();
    menu->setPosition({ 0.f, 0.f });
    menu->setAnchorPoint({ 0.f, 0.f });
    m_mainLayer->addChild(menu);

    m_downloadedTabSprite = GeodeTabSprite::create("GJ_sDownloadIcon_001.png", "Downloaded", 96.f);
    m_downloadedTabBtn = CCMenuItemSpriteExtra::create(
        m_downloadedTabSprite,
        this,
        menu_selector(SFXIndexPopup::selectDownloadedTab)
    );
    m_downloadedTabBtn->setPosition({ 95.f, kTabButtonY });
    menu->addChild(m_downloadedTabBtn);

    m_onlineTabSprite = GeodeTabSprite::create("geode.loader/globe.png", "Online Sounds", 106.f, true);
    m_onlineTabBtn = CCMenuItemSpriteExtra::create(
        m_onlineTabSprite,
        this,
        menu_selector(SFXIndexPopup::selectOnlineTab)
    );
    m_onlineTabBtn->setPosition({ 220.f, kTabButtonY });
    menu->addChild(m_onlineTabBtn);

    m_packsTabSprite = GeodeTabSprite::create("folderIcon_001.png", "Sound Packs", 96.f);
    m_packsTabBtn = CCMenuItemSpriteExtra::create(
        m_packsTabSprite,
        this,
        menu_selector(SFXIndexPopup::selectPacksTab)
    );
    m_packsTabBtn->setPosition({ 340.f, kTabButtonY });
    menu->addChild(m_packsTabBtn);

    m_downloadedWidgets = createTabWidgets();
    m_onlineWidgets = createTabWidgets();
    m_packWidgets = createTabWidgets();

    m_tabHost = CCLayerMultiplexR::create({
        m_downloadedWidgets.layer,
        m_onlineWidgets.layer,
        m_packWidgets.layer,
    });
    m_tabHost->setContentSize(m_mainLayer->getContentSize());
    m_tabHost->setPosition({ 0.f, -12.5f });
    m_mainLayer->addChild(m_tabHost);
    
    auto refreshSprite = CCSprite::createWithSpriteFrameName("GJ_updateBtn_001.png");
    refreshSprite->setScale(0.75f);

    auto refreshButton = CCMenuItemSpriteExtra::create(
        refreshSprite,
        this,
        menu_selector(SFXIndexPopup::refreshPage)
    );
    refreshButton->setPosition({ m_mainLayer->getContentWidth() - (refreshButton->getContentWidth() * 0.75f), (refreshButton->getContentHeight() * 0.75f ) });
    menu->addChild(refreshButton);

    if (settingsEnabled) {
        auto settingsSprite = CircleButtonSprite::create(
            CCSprite::createWithSpriteFrameName("geode.loader/settings.png"),
            CircleBaseColor::Green,
            CircleBaseSize::Medium
        );
        settingsSprite->setScale(0.75f);

        auto settingsButton = CCMenuItemSpriteExtra::create(
            settingsSprite,
            this,
            menu_selector(SFXIndexPopup::openModSettings)
        );
        settingsButton->setPosition({ m_mainLayer->getContentWidth() - ((settingsButton->getContentWidth() * 0.75f)), ((settingsButton->getContentHeight() * 0.75f) + settingsButton->getContentHeight() + 10.f) });
        menu->addChild(settingsButton);
    }

    auto folderSprite = CircleButtonSprite::create(
        CCSprite::createWithSpriteFrameName("folderIcon_001.png"),
        CircleBaseColor::Green,
        CircleBaseSize::Medium
    );
    folderSprite->setScale(0.75f);

    auto folderButton = CCMenuItemSpriteExtra::create(
        folderSprite,
        this,
        menu_selector(SFXIndexPopup::openSfxFolder)
    );
    folderButton->setPosition({ folderButton->getContentWidth() * 0.75f, ((folderButton->getContentHeight() * 0.75f)) });
    menu->addChild(folderButton);
    
    auto nextPageSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
    nextPageSprite->setFlipX(true);
    
    m_nextPageBtn = CCMenuItemSpriteExtra::create(
        nextPageSprite,
        this,
        menu_selector(SFXIndexPopup::nextPage)
    );
    m_nextPageBtn->setPosition({ 415.f, 145.f });
    menu->addChild(m_nextPageBtn);
    
    auto prevPageSprite = CCSprite::createWithSpriteFrameName("GJ_arrow_03_001.png");
    prevPageSprite->setFlipX(false);
    
    m_prevPageBtn = CCMenuItemSpriteExtra::create(
        prevPageSprite,
        this,
        menu_selector(SFXIndexPopup::prevPage)
    );
    m_prevPageBtn->setPosition({ 25.f, 145.f });
    menu->addChild(m_prevPageBtn);

    m_pageLabel = CCLabelBMFont::create("", "goldFont.fnt");
    m_pageLabel->setScale(0.5f);
    m_pageLabel->setAnchorPoint({ 1.f, 1.f });
    m_pageLabel->setPosition({ m_mainLayer->getContentWidth() - 10.f, m_mainLayer->getContentHeight() - 8.f });
    m_mainLayer->addChild(m_pageLabel);

    auto addFilterButtonToWidgets = [this](TabWidgets& widgets, Tab targetTab) {
        auto filterMenu = CCMenu::create();
        filterMenu->setPosition({ 0.f, 0.f });
        widgets.layer->addChild(filterMenu, 20);

        auto filterTopIcon = CCSprite::createWithSpriteFrameName("GJ_filterIcon_001.png");
        auto filterButtonSprite = EditorButtonSprite::create(
            filterTopIcon,
            EditorBaseColor::Green,
            EditorBaseSize::Normal
        );
        widgets.searchFilterBtn = CCMenuItemSpriteExtra::create(
            filterButtonSprite,
            this,
            menu_selector(SFXIndexPopup::openSearchFilters)
        );
        widgets.searchFilterBtn->setTag(static_cast<int>(targetTab));
        widgets.searchFilterBtn->setPosition({ 25.f, 200.f });
        filterMenu->addChild(widgets.searchFilterBtn);
    };

    addFilterButtonToWidgets(m_onlineWidgets, Tab::OnlineSounds);
    addFilterButtonToWidgets(m_packWidgets, Tab::SoundPacks);

    refreshSearchFilterButtonVisual(Tab::OnlineSounds);
    refreshSearchFilterButtonVisual(Tab::SoundPacks);
    m_activeTab = Tab::Downloaded;
    switchTab(Tab::OnlineSounds);
    
    return true;
}

void SFXIndexPopup::showLoading() {
    auto& widgets = activeWidgets();
    setTabLoading(widgets);
}

void SFXIndexPopup::loadingError(const char* text) {
    auto& widgets = activeWidgets();
    setTabError(widgets, text, false);
}

void SFXIndexPopup::clearList(TabWidgets& widgets) {
    widgets.list->m_contentLayer->removeAllChildrenWithCleanup(true);
    widgets.list->m_contentLayer->setContentSize({ widgets.list->m_contentLayer->getContentWidth(), 0.f });
}

void SFXIndexPopup::addSimpleRow(TabWidgets& widgets, int index, const std::string& title, const std::string& subtitle) {
    auto row = CCLayerColor::create(index % 2 == 0 ? ccc4(75, 75, 75, 255) : ccc4(50, 50, 50, 255));
    row->setContentSize({ 340.f, 80.f });

    auto titleLabel = CCLabelBMFont::create(title.c_str(), "bigFont.fnt");
    titleLabel->setAnchorPoint({ 0.f, 0.5f });
    titleLabel->setScale(0.45f);
    titleLabel->setPosition({ 10.f, 52.f });
    row->addChild(titleLabel);

    auto subtitleLabel = CCLabelBMFont::create(subtitle.c_str(), "goldFont.fnt");
    subtitleLabel->setAnchorPoint({ 0.f, 0.5f });
    subtitleLabel->setScale(0.35f);
    subtitleLabel->setPosition({ 10.f, 24.f });
    row->addChild(subtitleLabel);

    widgets.list->m_contentLayer->addChild(row);
}

void SFXIndexPopup::showOnlineResults(const matjson::Value& result) {
    auto& widgets = widgetsForTab(Tab::OnlineSounds);
    setTabContentVisible(widgets, true);

    clearList(widgets);

    if (result.contains("error")) {
        loadingError(result["error"].asString().unwrap().c_str());
        return;
    }

    populateTabRows(widgets, [&](int& index, float& totalHeight) {
        for (auto& sfxItem : result) {
            auto sfxId = sfxItem["id"].asString().unwrap();
            auto sfxUrl = sfxItem["url"].asString().unwrap();

            if (m_onlineInUse) {
                auto path = utils::getSfxDownloadPath(sfxId, sfxUrl);
                if (!std::filesystem::exists(path) || !utils::isOnlineSfxPathUsed(path)) {
                    continue;
                }
            }

            std::vector<std::string> tags;
            if (sfxItem.contains("tags") && sfxItem["tags"].isArray()) {
                for (auto const& tagValue : sfxItem["tags"]) {
                    if (tagValue.isString()) {
                        tags.push_back(tagValue.asString().unwrapOr(""));
                    }
                }
            }

            auto cell = SFXCell::create(
                index,
                sfxId,
                sfxItem["name"].asString().unwrap(),
                sfxUrl,
                sfxItem["downloads"].asInt().unwrap(),
                static_cast<int32_t>(sfxItem["createdAt"].asInt().unwrap()),
                false,
                true,
                tags,
                true,
                sfxItem.contains("lengthSeconds") ? sfxItem["lengthSeconds"].asDouble().unwrapOr(-1.0) : -1.0,
                sfxItem
            );
            cell->validateDownloadState();
            widgets.list->m_contentLayer->addChild(cell);
            totalHeight += cell->getContentHeight();
            widgets.list->m_contentLayer->setContentSize({ widgets.list->m_contentLayer->getContentSize().width, totalHeight });
            ++index;
        }
    });
}

void SFXIndexPopup::showPackResults(const matjson::Value& result) {
    auto& widgets = widgetsForTab(Tab::SoundPacks);
    setTabContentVisible(widgets, true);

    clearList(widgets);

    if (result.contains("error")) {
        loadingError(result["error"].asString().unwrap().c_str());
        return;
    }

    auto const& packs = result.contains("data") ? result["data"] : result;

    auto resolvePackSoundPath = [](std::string const& soundId) {
        auto fallback = utils::getSfxDownloadPath(soundId, std::string("/sounds/") + std::string(soundId) + ".wav");
        if (std::filesystem::exists(fallback)) {
            return fallback;
        }

        auto downloadDir = Mod::get()->getConfigDir() / "downloaded-sfx";
        if (!std::filesystem::exists(downloadDir)) {
            return fallback;
        }

        for (const auto& entry : std::filesystem::directory_iterator(downloadDir)) {
            if (!entry.is_regular_file()) {
                continue;
            }

            auto path = entry.path();
                auto ext = geode::utils::string::pathToString(path.extension());
            if (ext != ".wav" && ext != ".ogg" && ext != ".mp3") {
                continue;
            }

                if (geode::utils::string::pathToString(path.filename()).ends_with(".16.wav")) {
                continue;
            }

            auto metadata = utils::getDownloadedSfxMetadata(path);
            if (metadata.id == soundId) {
                return path;
            }
        }

        return fallback;
    };

    populateTabRows(widgets, [&](int& index, float& totalHeight) {
        for (auto& packItem : packs) {
            std::string id = "unknown-id";
            if (packItem.contains("id")) {
                id = packItem["id"].asString().unwrap();
            }

            std::string name = id;
            if (packItem.contains("name")) {
                name = packItem["name"].asString().unwrap();
            }

            int trackCount = 0;
            std::vector<std::string> soundIds;
            if (packItem.contains("ids")) {
                for (auto const& idValue : packItem["ids"]) {
                    if (idValue.isString()) {
                        soundIds.push_back(idValue.asString().unwrapOr(""));
                    }
                    ++trackCount;
                }
            }

            if (m_packInUse) {
                bool allUsed = !soundIds.empty();
                for (auto const& soundId : soundIds) {
                    auto path = resolvePackSoundPath(soundId);
                    if (!std::filesystem::exists(path) || !utils::isOnlineSfxPathUsed(path)) {
                        allUsed = false;
                        break;
                    }
                }

                if (!allUsed) {
                    continue;
                }
            }

            int downloads = 0;
            if (packItem.contains("downloads")) {
                downloads = packItem["downloads"].asInt().unwrapOr(0);
            }

            int32_t createdAt = 0;
            if (packItem.contains("createdAt")) {
                createdAt = static_cast<int32_t>(packItem["createdAt"].asInt().unwrapOr(0));
            }

            auto cell = SFXPackCell::create(index, id, name, soundIds, downloads, createdAt);
            cell->validateDownloadState();
            widgets.list->m_contentLayer->addChild(cell);
            totalHeight += cell->getContentHeight();
            widgets.list->m_contentLayer->setContentSize({ widgets.list->m_contentLayer->getContentSize().width, totalHeight });
            ++index;
        }
    });
}

void SFXIndexPopup::showDownloadedResults() {
    auto& widgets = widgetsForTab(Tab::Downloaded);
    setTabContentVisible(widgets, true);

    clearList(widgets);

    std::filesystem::path downloadDir = Mod::get()->getConfigDir() / "downloaded-sfx";
    if (!std::filesystem::exists(downloadDir)) {
        loadingError("No downloaded sounds yet.");
        return;
    }

    std::vector<std::filesystem::path> downloadedFiles;
    for (const auto& entry : std::filesystem::directory_iterator(downloadDir)) {
        if (!entry.is_regular_file()) {
            continue;
        }

        auto path = entry.path();
            auto ext = geode::utils::string::pathToString(path.extension());
        if (ext != ".wav" && ext != ".ogg" && ext != ".mp3") {
            continue;
        }

            if (geode::utils::string::pathToString(path.filename()).ends_with(".16.wav")) {
            continue;
        }

        downloadedFiles.push_back(path);
    }

    std::sort(downloadedFiles.begin(), downloadedFiles.end(), [](auto const& a, auto const& b) {
            return geode::utils::string::pathToString(a.filename()) < geode::utils::string::pathToString(b.filename());
    });

    bool hasRows = !downloadedFiles.empty();
    constexpr int kDownloadedPageSize = 10;
    int maxPage = std::max(1, static_cast<int>((downloadedFiles.size() + kDownloadedPageSize - 1) / kDownloadedPageSize));
    int page = std::clamp(pageForTab(Tab::Downloaded), 1, maxPage);
    pageForTab(Tab::Downloaded) = page;

    int startIdx = (page - 1) * kDownloadedPageSize;
    int endIdx = std::min(startIdx + kDownloadedPageSize, static_cast<int>(downloadedFiles.size()));

    populateTabRows(widgets, [&](int& index, float& totalHeight) {
        for (int i = startIdx; i < endIdx; ++i) {
            auto const& path = downloadedFiles[i];
            auto metadata = utils::getDownloadedSfxMetadata(path);
            auto metadataPath = utils::getSfxMetadataPath(path);
            if (!std::filesystem::exists(metadataPath)) {
                    auto fallbackName = geode::utils::string::pathToString(path.filename());
                metadata.id = fallbackName;
                metadata.name = fallbackName;
                    metadata.path = geode::utils::string::pathToString(std::filesystem::absolute(path));
            }
            auto cell = SFXCell::create(
                index,
                metadata.id,
                metadata.name,
                    metadata.url.empty() ? "/sounds/" + geode::utils::string::pathToString(path.filename()) : metadata.url,
                0,
                0,
                true,
                true,
                std::vector<std::string>(metadata.tags.begin(), metadata.tags.end()),
                true,
                metadata.lengthSeconds
            );
            cell->validateDownloadState();
            widgets.list->m_contentLayer->addChild(cell);
            totalHeight += cell->getContentHeight();
            widgets.list->m_contentLayer->setContentSize({ widgets.list->m_contentLayer->getContentSize().width, totalHeight });
            ++index;
        }
    });

    if (!hasRows) {
        loadingError("No downloaded sounds yet.");
        return;
    }

    if (m_prevPageBtn) {
        m_prevPageBtn->setVisible(page > 1);
    }
    if (m_nextPageBtn) {
        m_nextPageBtn->setVisible(page < maxPage);
    }
    setPageText(fmt::format("Page {} of {}", page, maxPage));
}

void SFXIndexPopup::updateTabVisuals() {
    if (m_downloadedTabSprite) {
        m_downloadedTabSprite->select(m_activeTab == Tab::Downloaded);
        m_downloadedTabSprite->disable(m_activeTab != Tab::Downloaded);
    }
    if (m_onlineTabSprite) {
        m_onlineTabSprite->select(m_activeTab == Tab::OnlineSounds);
        m_onlineTabSprite->disable(m_activeTab != Tab::OnlineSounds);
    }
    if (m_packsTabSprite) {
        m_packsTabSprite->select(m_activeTab == Tab::SoundPacks);
        m_packsTabSprite->disable(m_activeTab != Tab::SoundPacks);
    }
}

void SFXIndexPopup::refreshSearchFilterButtonVisual(Tab tab) {
    auto& widgets = widgetsForTab(tab);
    if (!widgets.searchFilterBtn) {
        return;
    }

    auto topIcon = CCSprite::createWithSpriteFrameName("GJ_filterIcon_001.png");
    if (!topIcon) {
        return;
    }

    auto color = filtersSetForTab(tab) ? EditorBaseColor::Aqua : EditorBaseColor::Green;
    auto base = EditorButtonSprite::create(topIcon, color, EditorBaseSize::Normal);
    widgets.searchFilterBtn->setNormalImage(base);
}

void SFXIndexPopup::switchTab(Tab tab) {
    if (m_activeTab == tab) {
        return;
    }

    m_activeTab = tab;
    m_tabHost->switchTo(static_cast<unsigned>(tab));
    updateTabVisuals();
    refreshPage(nullptr);
}

void SFXIndexPopup::selectDownloadedTab(CCObject*) {
    switchTab(Tab::Downloaded);
}

void SFXIndexPopup::selectOnlineTab(CCObject*) {
    switchTab(Tab::OnlineSounds);
}

void SFXIndexPopup::selectPacksTab(CCObject*) {
    switchTab(Tab::SoundPacks);
}

void SFXIndexPopup::refreshPage(CCObject*) {
    auto requestedTab = m_activeTab;
    int requestedPage = pageForTab(requestedTab);
    std::string query = trim(queryForTab(requestedTab));
    bool recent = recentForTab(requestedTab);
    bool inUse = inUseForTab(requestedTab);
    bool usingSearchQuery = !query.empty();

    auto shouldShowResetToFirstPage = [](std::string const& error) {
        return error.find("404") != std::string::npos ||
               error.find("overflow") != std::string::npos ||
               error.find("out of range") != std::string::npos ||
               error.find("page") != std::string::npos;
    };

    if (m_activeTab == Tab::Downloaded) {
        showDownloadedResults();
        return;
    }

    showLoading();

    auto onSuccess = [this, requestedTab, requestedPage, usingSearchQuery, inUse, shouldShowResetToFirstPage](const matjson::Value& result) {
        auto payload = result.contains("data") ? result["data"] : result;

        if (requestedTab == Tab::OnlineSounds) {
            showOnlineResults(payload);
        } else {
            showPackResults(payload);
        }

        if (m_activeTab != requestedTab) {
            return;
        }

        if (!result.contains("error")) {
            if (usingSearchQuery || inUse) {
                setPaginationVisible(false);

                int resultCount = 0;
                auto& widgets = widgetsForTab(requestedTab);
                if (widgets.list && widgets.list->m_contentLayer) {
                    resultCount = static_cast<int>(widgets.list->m_contentLayer->getChildrenCount());
                }
                setPageText(fmt::format("Filtered Results ({})", resultCount));
            } else {
                int maxPage = 1;
                if (result.contains("totalPages")) {
                    maxPage = result["totalPages"].asInt().unwrap();
                }

                if (m_prevPageBtn) {
                    m_prevPageBtn->setVisible(requestedPage > 1);
                }
                if (m_nextPageBtn) {
                    m_nextPageBtn->setVisible(requestedPage < maxPage);
                }

                setPageText(fmt::format("Page {} of {}", requestedPage, maxPage));
            }
        } else {
            std::string errorStr = result["error"].asString().unwrap();
            auto& widgets = widgetsForTab(requestedTab);
            setTabError(widgets, errorStr.c_str(), shouldShowResetToFirstPage(errorStr));
        }
    };

    auto onError = [this, requestedTab, usingSearchQuery, shouldShowResetToFirstPage](const matjson::Value& result) {
        if (m_activeTab != requestedTab) {
            return;
        }

        std::string errorStr = result["error"].asString().unwrap();
        if (!usingSearchQuery && requestedTab == Tab::SoundPacks && errorStr.find("404") != std::string::npos) {
            auto& widgets = widgetsForTab(requestedTab);
            setTabError(widgets, "No sound packs yet.", true);
            return;
        }
        auto& widgets = widgetsForTab(requestedTab);
        setTabError(widgets, errorStr.c_str(), shouldShowResetToFirstPage(errorStr));
    };

    if (requestedTab == Tab::OnlineSounds) {
        if (usingSearchQuery) {
            DSRequest::get()->searchSFX(
                query,
                100,
                onSuccess,
                onError
            );
            return;
        }

        DSRequest::get()->getTopSFXList(
            requestedPage,
            recent,
            onSuccess,
            onError
        );
        return;
    }

    if (usingSearchQuery) {
        DSRequest::get()->searchPacks(
            query,
            100,
            onSuccess,
            onError
        );
        return;
    }

    DSRequest::get()->getTopPacksList(
        requestedPage,
        recent,
        onSuccess,
        onError
    );
}

void SFXIndexPopup::nextPage(CCObject* sender) {
    pageForTab(m_activeTab) += 1;
    refreshPage(sender);
}

void SFXIndexPopup::prevPage(CCObject* sender) {
    int& page = pageForTab(m_activeTab);
    page = std::max(1, page - 1);
    refreshPage(sender);
}

void SFXIndexPopup::openSearchFilters(CCObject*) {
    if (m_activeTab != Tab::OnlineSounds && m_activeTab != Tab::SoundPacks) {
        return;
    }

    auto targetTab = m_activeTab;
    auto& tabQuery = queryForTab(targetTab);
    auto& tabRecent = recentForTab(targetTab);
    auto& tabInUse = inUseForTab(targetTab);

    if (filtersSetForTab(targetTab)) {
        tabQuery.clear();
        tabRecent = false;
        tabInUse = false;
        pageForTab(targetTab) = 1;
        refreshSearchFilterButtonVisual(targetTab);
        refreshPage(nullptr);
        return;
    }

    if (auto popup = SearchFilterPopup::create(tabQuery, tabRecent, tabInUse, [this, targetTab](std::string query, bool recent, bool inUse) {
        queryForTab(targetTab) = trim(std::move(query));
        recentForTab(targetTab) = recent;
        inUseForTab(targetTab) = inUse;
        pageForTab(targetTab) = 1;
        refreshSearchFilterButtonVisual(targetTab);
        if (m_activeTab == targetTab) {
            refreshPage(nullptr);
        }
    })) {
        popup->show();
    }
}

SFXIndexPopup* SFXIndexPopup::create(bool settingsEnabled) {
    auto ret = new SFXIndexPopup();
    if (ret->init(settingsEnabled)) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}

void SFXIndexPopup::openModSettings(CCObject* sender) {
    openSettingsPopup(Mod::get());
}

void SFXIndexPopup::openSfxFolder(CCObject*) {
    auto downloadDir = Mod::get()->getConfigDir() / "downloaded-sfx";
    std::error_code ec;
    std::filesystem::create_directories(downloadDir, ec);
    utils::file::openFolder(geode::utils::string::pathToString(downloadDir));
}

void SFXIndexPopup::resetToFirstPage(CCObject*) {
    pageForTab(m_activeTab) = 1;
    refreshPage(nullptr);
}
