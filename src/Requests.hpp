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

        void getTopPacksList(std::function<void(const matjson::Value&)> onComplete) {
            std::string url = fmt::format("{}/getTopPacksList", Mod::get()->getSettingValue<std::string>("server-url"));

            m_listener.bind([onComplete](web::WebTask::Event* e) {
                const auto error_unknown = []{
                    matjson::Value val = matjson::Value::object();
                    val["error"] = "There was an issue processing the request.";
                    return val;
                }();

                matjson::Value result = error_unknown;

                if (web::WebResponse* res = e->getValue()) {
                    auto jsonOpt = res->json();
                    if (jsonOpt.isOk()) {
                        result = jsonOpt.unwrap();
                        onComplete(result);
                    } else {
                        result["error"] = "Invalid JSON response.";
                    }
                } else if (e->isCancelled()) {
                    result = matjson::Value::object();
                    result["error"] = "The request was cancelled.";
                    // add error function here later or smth
                }
            });

            auto req = web::WebRequest();

            m_listener.setFilter(req.get(url));
        }

        void getTopSFXList(std::function<void(const matjson::Value&)> onComplete) {
            std::string url = fmt::format("{}/getTopSFXList", Mod::get()->getSettingValue<std::string>("server-url"));

            m_listener.bind([onComplete](web::WebTask::Event* e) {
                const auto error_unknown = []{
                    matjson::Value val = matjson::Value::object();
                    val["error"] = "There was an issue processing the request.";
                    return val;
                }();

                matjson::Value result = error_unknown;

                if (web::WebResponse* res = e->getValue()) {
                    auto jsonOpt = res->json();
                    if (jsonOpt.isOk()) {
                        result = jsonOpt.unwrap();
                        onComplete(result);
                    } else {
                        result["error"] = "Invalid JSON response.";
                    }
                } else if (e->isCancelled()) {
                    result = matjson::Value::object();
                    result["error"] = "The request was cancelled.";
                    // add error function here later or smth
                }
            });

            auto req = web::WebRequest();

            m_listener.setFilter(req.get(url));
        }

        void getPackInfo(const std::string& packID, std::function<void(const matjson::Value&)> onComplete) {
            std::string url = fmt::format("{}/pack/{}", Mod::get()->getSettingValue<std::string>("server-url"), packID);

            m_listener.bind([onComplete](web::WebTask::Event* e) {
                const auto error_unknown = []{
                    matjson::Value val = matjson::Value::object();
                    val["error"] = "There was an issue processing the request.";
                    return val;
                }();

                matjson::Value result = error_unknown;

                if (web::WebResponse* res = e->getValue()) {
                    auto jsonOpt = res->json();
                    if (jsonOpt.isOk()) {
                        result = jsonOpt.unwrap();
                        onComplete(result);
                    } else {
                        result["error"] = "Invalid JSON response.";
                    }
                } else if (e->isCancelled()) {
                    result = matjson::Value::object();
                    result["error"] = "The request was cancelled.";
                    // add error function here later or smth
                }
            });

            auto req = web::WebRequest();

            m_listener.setFilter(req.get(url));
        }

        void getSFXInfo(const std::string& sfxID, std::function<void(const matjson::Value&)> onComplete) {
            std::string url = fmt::format("{}/sfx/{}", Mod::get()->getSettingValue<std::string>("server-url"), sfxID);

            m_listener.bind([onComplete](web::WebTask::Event* e) {
                const auto error_unknown = []{
                    matjson::Value val = matjson::Value::object();
                    val["error"] = "There was an issue processing the request.";
                    return val;
                }();

                matjson::Value result = error_unknown;

                if (web::WebResponse* res = e->getValue()) {
                    auto jsonOpt = res->json();
                    if (jsonOpt.isOk()) {
                        result = jsonOpt.unwrap();
                        onComplete(result);
                    } else {
                        result["error"] = "Invalid JSON response.";
                    }
                } else if (e->isCancelled()) {
                    result = matjson::Value::object();
                    result["error"] = "The request was cancelled.";
                    // add error function here later or smth
                }
            });

            auto req = web::WebRequest();

            m_listener.setFilter(req.get(url));
        }

    private:
        DSRequest() = default;

        DSRequest(const DSRequest&) = delete;
        DSRequest& operator=(const DSRequest&) = delete;

        EventListener<web::WebTask> m_listener;
    };
}
