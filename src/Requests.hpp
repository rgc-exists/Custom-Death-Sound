#pragma once

#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/loader/Event.hpp>

using namespace geode::prelude;
using namespace geode::utils::web;

namespace deathsounds {
    class DSRequest {
    public:
        static DSRequest* get() {
            static DSRequest instance;
            return &instance;
        }

        void getTopPacksList(int page, bool recent, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            std::vector<std::pair<std::string, std::string>> params = { {"page", std::to_string(page)} };
            if (recent) {
                params.emplace_back("recent", "1");
            }
            makeGetRequest("/getTopPacksList", params, std::move(onComplete), std::move(onError));
        }

        void getTopSFXList(int page, bool recent, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            std::vector<std::pair<std::string, std::string>> params = { {"page", std::to_string(page)} };
            if (recent) {
                params.emplace_back("recent", "1");
            }
            makeGetRequest("/getTopSFXList", params, std::move(onComplete), std::move(onError));
        }

        void getPackInfo(const std::string& packID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            makeGetRequest(fmt::format("/pack/{}", packID), {}, std::move(onComplete), std::move(onError));
        }

        void incrementPackDownload(const std::string& packID, std::function<void(const matjson::Value&)> onComplete = nullptr, std::function<void(const matjson::Value&)> onError = nullptr) {
            makeGetRequestWithListener(m_incrementListener, fmt::format("/pack/{}/download", packID), {}, std::move(onComplete), std::move(onError));
        }

        void incrementSFXDownload(const std::string& sfxID, std::function<void(const matjson::Value&)> onComplete = nullptr, std::function<void(const matjson::Value&)> onError = nullptr) {
            makeGetRequestWithListener(m_incrementListener, fmt::format("/sfx/{}/download", sfxID), {}, std::move(onComplete), std::move(onError));
        }

        void getSFXInfo(const std::string& sfxID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            makeGetRequest(fmt::format("/sfx/{}", sfxID), {}, std::move(onComplete), std::move(onError));
        }

    private:
        DSRequest() = default;
        DSRequest(const DSRequest&) = delete;
        DSRequest& operator=(const DSRequest&) = delete;

        async::TaskHolder<WebResponse> m_listener;
        async::TaskHolder<WebResponse> m_incrementListener;

        void makeGetRequestWithListener(
            async::TaskHolder<WebResponse>& listener,
            const std::string& endpointFmt,
            const std::vector<std::pair<std::string, std::string>>& queryParams,
            std::function<void(const matjson::Value&)> onComplete,
            std::function<void(const matjson::Value&)> onError
        ) {
            std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
            std::string url = fmt::format("{}{}", baseUrl, endpointFmt);

            auto req = web::WebRequest();
            req.timeout(std::chrono::seconds(30));

            for (const auto& [key, value] : queryParams) {
                req.param(key, value);
            }

            listener.spawn(
                req.get(url),
                [onComplete, onError](WebResponse value) {
                    matjson::Value result = matjson::Value::object();
                    result["error"] = "There was an issue processing the request.";

                    if (value.ok()) {
                        auto jsonOpt = value.json();
                        if (jsonOpt.isOk()) {
                            result = jsonOpt.unwrap();
                            if (onComplete) {
                                onComplete(result);
                            }
                            return;
                        } else {
                            result["error"] = value.string().unwrap();
                            if (onError) {
                                onError(result);
                            }
                        }
                    } else {
                        result["error"] = "Request failed with code " + std::to_string(value.code());
                        if (onError) {
                            onError(result);
                        }
                    }
                }
            );
        }

        void makeGetRequest(
            const std::string& endpointFmt,
            const std::vector<std::pair<std::string, std::string>>& queryParams,
            std::function<void(const matjson::Value&)> onComplete,
            std::function<void(const matjson::Value&)> onError
        ) {
            makeGetRequestWithListener(m_listener, endpointFmt, queryParams, std::move(onComplete), std::move(onError));
        }
    };
}
