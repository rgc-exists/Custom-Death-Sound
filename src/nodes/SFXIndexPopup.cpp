#include "SFXIndexPopup.hpp"
#include "SFXCell.hpp"
#include "../Requests.hpp"
#include "../Utils.hpp"
#include <Geode/ui/BasedButton.hpp>
#include <algorithm>
#include <filesystem>

using namespace geode::prelude;

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
    widgets.border->setVisible(false);
    widgets.clipping->setVisible(false);
    widgets.error->setVisible(false);
    if (m_pageLabel) {
        m_pageLabel->setVisible(true);
    }
}

void SFXIndexPopup::setTabContentVisible(TabWidgets& widgets, bool showPagination) {
    widgets.loading->setVisible(false);
    widgets.error->setVisible(false);
    widgets.clipping->setVisible(true);
    widgets.border->setVisible(true);
    setPaginationVisible(showPagination);
    if (m_pageLabel) {
        m_pageLabel->setVisible(true);
    }
}

void SFXIndexPopup::setTabError(TabWidgets& widgets, char const* text) {
    widgets.loading->setVisible(false);
    widgets.error->setString(text);
    widgets.error->setVisible(true);
    clearList(widgets);
    widgets.clipping->setVisible(true);
    widgets.border->setVisible(true);
    setPaginationVisible(false);
    if (m_pageLabel) {
        m_pageLabel->setVisible(false);
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

    widgets.border = deathsounds::Border::create(widgets.list, { 75, 75, 75, 255 }, { 340.f, 220.f });
    widgets.border->setPosition({ 0.f, 0.f });
    widgets.border->setVisible(false);
    widgets.clipping->addChild(widgets.border);
    widgets.layer->addChild(widgets.clipping);

    widgets.error = CCLabelBMFont::create("", "bigFont.fnt", 350.f);
    widgets.error->setPosition(widgets.layer->getContentSize() / 2);
    widgets.error->setScale(0.5f);
    widgets.error->setVisible(false);
    widgets.layer->addChild(widgets.error);

    return widgets;
}

bool SFXIndexPopup::init() {
        constexpr float kTabButtonY = 248.f;

    if (!Popup::init(440.f, 290.f, "GJ_square02.png")) return false;

    this->setTitle("Death SFX Index");

    auto menu = CCMenu::create();
    menu->setPosition({ 0.f, 0.f });
    menu->setAnchorPoint({ 0.f, 0.f });
    m_mainLayer->addChild(menu);

    m_downloadedTabBtn = geode::TabButton::create(
        geode::TabBaseColor::Unselected,
        geode::TabBaseColor::Selected,
        "Downloaded",
        this,
        menu_selector(SFXIndexPopup::selectDownloadedTab)
    );
    m_downloadedTabBtn->setPosition({ 95.f, kTabButtonY });
    menu->addChild(m_downloadedTabBtn);

    m_onlineTabBtn = geode::TabButton::create(
        geode::TabBaseColor::Unselected,
        geode::TabBaseColor::Selected,
        "Online Sounds",
        this,
        menu_selector(SFXIndexPopup::selectOnlineTab)
    );
    m_onlineTabBtn->setPosition({ 220.f, kTabButtonY });
    menu->addChild(m_onlineTabBtn);

    m_packsTabBtn = geode::TabButton::create(
        geode::TabBaseColor::Unselected,
        geode::TabBaseColor::Selected,
        "Sound Packs",
        this,
        menu_selector(SFXIndexPopup::selectPacksTab)
    );
    m_packsTabBtn->setPosition({ 340.f, kTabButtonY });
    menu->addChild(m_packsTabBtn);

    m_downloadedWidgets = createTabWidgets();
    m_onlineWidgets = createTabWidgets();
    m_packWidgets = createTabWidgets();

    m_tabHost = CCLayerMultiplex::create(
        m_downloadedWidgets.layer,
        m_onlineWidgets.layer,
        m_packWidgets.layer,
        nullptr
    );
    m_tabHost->setContentSize(m_mainLayer->getContentSize());
    m_tabHost->setPosition({ 0.f, 0.f });
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
    setTabError(widgets, text);
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
            auto cell = deathsounds::SFXCell::create(
                index,
                sfxItem["id"].asString().unwrap(),
                sfxItem["name"].asString().unwrap(),
                sfxItem["url"].asString().unwrap(),
                sfxItem["downloads"].asInt().unwrap(),
                static_cast<int32_t>(sfxItem["createdAt"].asInt().unwrap())
            );
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

    populateTabRows(widgets, [&](int& index, float& totalHeight) {
        for (auto& packItem : result) {
            std::string id = "unknown-id";
            if (packItem.contains("id")) {
                id = packItem["id"].asString().unwrap();
            }

            std::string name = id;
            if (packItem.contains("name")) {
                name = packItem["name"].asString().unwrap();
            }

            addSimpleRow(widgets, index, name, fmt::format("Pack ID: {}", id));
            totalHeight += 80.f;
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
        auto ext = path.extension().string();
        if (ext != ".wav" && ext != ".ogg" && ext != ".mp3") {
            continue;
        }

        if (path.filename().string().ends_with(".16.wav")) {
            continue;
        }

        downloadedFiles.push_back(path);
    }

    std::sort(downloadedFiles.begin(), downloadedFiles.end(), [](auto const& a, auto const& b) {
        return a.filename().string() < b.filename().string();
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
            auto metadata = deathsounds::utils::getDownloadedSfxMetadata(path);
            auto cell = deathsounds::SFXCell::create(
                index,
                metadata.id,
                metadata.name,
                "/sounds/" + path.filename().string(),
                0,
                0
            );
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
    if (m_downloadedTabBtn) {
        m_downloadedTabBtn->toggle(m_activeTab == Tab::Downloaded);
    }
    if (m_onlineTabBtn) {
        m_onlineTabBtn->toggle(m_activeTab == Tab::OnlineSounds);
    }
    if (m_packsTabBtn) {
        m_packsTabBtn->toggle(m_activeTab == Tab::SoundPacks);
    }
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

    if (m_activeTab == Tab::Downloaded) {
        showDownloadedResults();
        return;
    }

    showLoading();

    auto onSuccess = [this, requestedTab, requestedPage](const matjson::Value& result) {
        if (requestedTab == Tab::OnlineSounds) {
            showOnlineResults(result["data"]);
        } else {
            showPackResults(result["data"]);
        }

        if (m_activeTab != requestedTab) {
            return;
        }

        if (!result.contains("error")) {
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
        } else {
            std::string errorStr = result["error"].asString().unwrap();
            loadingError(errorStr.c_str());
        }
    };

    auto onError = [this, requestedTab](const matjson::Value& result) {
        if (m_activeTab != requestedTab) {
            return;
        }

        std::string errorStr = result["error"].asString().unwrap();
        if (requestedTab == Tab::SoundPacks && errorStr.find("404") != std::string::npos) {
            loadingError("No sound packs yet.");
            return;
        }
        loadingError(errorStr.c_str());
    };

    if (requestedTab == Tab::OnlineSounds) {
        deathsounds::DSRequest::get()->getTopSFXList(
            requestedPage,
            m_recent,
            onSuccess,
            onError
        );
        return;
    }

    deathsounds::DSRequest::get()->getTopPacksList(
        requestedPage,
        m_recent,
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

SFXIndexPopup* SFXIndexPopup::create() {
    auto ret = new SFXIndexPopup();
    if (ret->init()) {
        ret->autorelease();
        return ret;
    }

    delete ret;
    return nullptr;
}