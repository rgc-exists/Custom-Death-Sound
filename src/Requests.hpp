/// @todo
/*
    planned endpoint: deathsounds.omgrod.me
    /getTopPacksList = get top packs (recent included) - GET
    /getTopSFXList = get top sfx (recent included) - GET
    /pack/PackIDHere = get pack info - GET
    /sfx/SFXIDHere = get sfx info - GET
    /uploadSFX = upload sound - POST
    /uploadPack = upload pack - POST
*/

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

        void getTopPacksList(bool recent, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            std::string query = recent ? "?recent=1" : "";
            makeGetRequest("/getTopPacksList", query, std::move(onComplete), std::move(onError));
        }

        void getTopSFXList(bool recent, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            std::string query = recent ? "?recent=1" : "";
            makeGetRequest("/getTopSFXList", query, std::move(onComplete), std::move(onError));
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

        void makeGetRequest(const std::string& endpointFmt, const std::string& query, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
            std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
            std::string url = fmt::format("{}{}{}", baseUrl, endpointFmt, query);

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
                }
            });

            auto req = web::WebRequest();
            req.timeout(std::chrono::seconds(15));
            m_listener.setFilter(req.get(url));
        }
    };
}
