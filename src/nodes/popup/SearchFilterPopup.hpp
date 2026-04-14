#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class SearchFilterPopup : public Popup {
private:
    std::function<void(std::string, bool, bool)> m_onApply;
    TextInput* m_queryInput = nullptr;
    CCMenuItemToggler* m_recentToggle = nullptr;
    CCMenuItemToggler* m_inUseToggle = nullptr;
    std::string m_query;
    bool m_recent = false;
    bool m_inUse = false;

    bool init(std::string query, bool recent, bool inUse, std::function<void(std::string, bool, bool)> onApply);
    void applyAndClose();

    void onClear(CCObject*);
    void onApplyPressed(CCObject*);
    void onRecentToggled(CCObject*);
    void onInUseToggled(CCObject*);

public:
    static SearchFilterPopup* create(std::string query, bool recent, bool inUse, std::function<void(std::string, bool, bool)> onApply);
};
