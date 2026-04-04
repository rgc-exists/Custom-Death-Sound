#pragma once

#include <Geode/Geode.hpp>
#include <string>
#include <functional>

using namespace geode::prelude;

class SearchFilterPopup : public geode::Popup {
private:
    std::function<void(std::string, bool)> m_onApply;
    geode::TextInput* m_queryInput = nullptr;
    CCMenuItemToggler* m_recentToggle = nullptr;
    std::string m_query;
    bool m_recent = false;

    bool init(std::string query, bool recent, std::function<void(std::string, bool)> onApply);
    void applyAndClose();

    void onClear(CCObject*);
    void onApplyPressed(CCObject*);
    void onRecentToggled(CCObject*);

public:
    static SearchFilterPopup* create(std::string query, bool recent, std::function<void(std::string, bool)> onApply);
};
