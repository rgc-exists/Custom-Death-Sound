#pragma once

#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/loader/Event.hpp>

using namespace geode::prelude;
using namespace geode::utils::web;

class DSRequest {
public:
    static DSRequest* get();

    void uploadSFX(const std::string& filePath, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void updateSFX(const std::string& sfxID, const matjson::Value& body, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void replaceSFXFile(const std::string& sfxID, const std::string& filePath, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void deleteSFX(const std::string& sfxID, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void viewSFXTagAudit(const std::string& sfxID, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void verifySFXFileExists(const std::string& sfxID, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);

    void macroDeleteMissingFiles(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void macroAutoAssignTags(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void macroCalculateLengths(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void macroTrimSilence(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);

    void uploadPack(const matjson::Value& body, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void updatePack(const std::string& packID, const matjson::Value& body, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void deletePack(const std::string& packID, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);

    void listUsers(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void deleteUser(const std::string& userId, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);

    void getAdminNetworkInfo(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void resetAdminRateLimit(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);

    void getTopPacksList(int page, bool recent, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void getTopSFXList(int page, bool recent, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);

    void searchSFX(const std::string& query, int limit, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void searchPacks(const std::string& query, int limit, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);

    void getPackInfo(const std::string& packID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);
    void getSFXInfo(const std::string& sfxID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);

    void incrementPackDownload(const std::string& packID, std::function<void(const matjson::Value&)> onComplete = nullptr, std::function<void(const matjson::Value&)> onError = nullptr);
    void incrementSFXDownload(const std::string& sfxID, std::function<void(const matjson::Value&)> onComplete = nullptr, std::function<void(const matjson::Value&)> onError = nullptr);

private:
    DSRequest() = default;
    DSRequest(const DSRequest&) = delete;
    DSRequest& operator=(const DSRequest&) = delete;

public:
    void checkModToken(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError);

    async::TaskHolder<WebResponse> m_listener;
    async::TaskHolder<WebResponse> m_incrementListener;

    void makeGetRequestWithListener(
        async::TaskHolder<WebResponse>& listener,
        const std::string& endpointFmt,
        const std::vector<std::pair<std::string, std::string>>& queryParams,
        std::function<void(const matjson::Value&)> onComplete,
        std::function<void(const matjson::Value&)> onError
    );

    void makeGetRequest(
        const std::string& endpointFmt,
        const std::vector<std::pair<std::string, std::string>>& queryParams,
        std::function<void(const matjson::Value&)> onComplete,
        std::function<void(const matjson::Value&)> onError
    );
};
