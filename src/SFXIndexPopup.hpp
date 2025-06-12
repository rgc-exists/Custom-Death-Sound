#pragma once

#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/loader/Event.hpp>

using namespace geode::prelude;

namespace deathsounds {
    class DSRequest {
    public:
        static DSRequest* get() {
            static DSRequest instance;
            return &instance;
        }

        void getTopPacksList(std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            makeGetRequest("/getTopPacksList", "", std::move(onComplete), std::move(onError));
        }

        void getTopSFXList(std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            makeGetRequest("/getTopSFXList", "", std::move(onComplete), std::move(onError));
        }

        void getPackInfo(const std::string& packID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            makeGetRequest("/pack/{}", packID, std::move(onComplete), std::move(onError));
        }

        void getSFXInfo(const std::string& sfxID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            makeGetRequest("/sfx/{}", sfxID, std::move(onComplete), std::move(onError));
        }

    private:
        DSRequest() = default;
        DSRequest(const DSRequest&) = delete;
        DSRequest& operator=(const DSRequest&) = delete;

        EventListener<web::WebTask> m_listener;

        void makeGetRequest(const std::string& endpointFmt, const std::string& id, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
            std::string url = id.empty() ? fmt::format("{}{}", baseUrl, endpointFmt)
                                         : fmt::format("{}{}{}", baseUrl, endpointFmt, id);

            m_listener.bind([onComplete, onError](web::WebTask::Event* e) {
                matjson::Value result = matjson::Value::object();

                result["error"] = "There was an issue processing the request.";

                if (web::WebResponse* res = e->getValue()) {
                    auto jsonOpt = res->json();
                    if (jsonOpt.isOk()) {
                        result = jsonOpt.unwrap();
                        onComplete(result);
                        return;
                    } else {
                        result["error"] = res->string().unwrap();
                        onError(result);
                    }
                } else if (e->isCancelled()) {
                    result["error"] = "The request was cancelled.";
                    onError(result);
                } else {
                    log::debug("Something happened. Try again later.");
                }
            });

            auto req = web::WebRequest();
            req.timeout(std::chrono::seconds(15));
            m_listener.setFilter(req.get(url));
        }
    };
}
