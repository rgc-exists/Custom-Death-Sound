#include "Requests.hpp"

DSRequest* DSRequest::get()  {
    static DSRequest instance;
    return &instance;
}

void DSRequest::getTopPacksList(int page, bool recent, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::vector<std::pair<std::string, std::string>> params = { {"page", std::to_string(page)} };
    if (recent) {
        params.emplace_back("recent", "1");
    }
    makeGetRequest("/getTopPacksList", params, std::move(onComplete), std::move(onError));
}

void DSRequest::getTopSFXList(int page, bool recent, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::vector<std::pair<std::string, std::string>> params = { {"page", std::to_string(page)} };
    if (recent) {
        params.emplace_back("recent", "1");
    }
    makeGetRequest("/getTopSFXList", params, std::move(onComplete), std::move(onError));
}

void DSRequest::searchSFX(const std::string& query, int limit, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::vector<std::pair<std::string, std::string>> params = {
        {"query", query},
        {"limit", std::to_string(limit)}
    };
    makeGetRequest("/sfx/search", params, std::move(onComplete), std::move(onError));
}

void DSRequest::searchPacks(const std::string& query, int limit, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::vector<std::pair<std::string, std::string>> params = {
        {"query", query},
        {"limit", std::to_string(limit)}
    };
    makeGetRequest("/pack/search", params, std::move(onComplete), std::move(onError));
}

void DSRequest::getPackInfo(const std::string& packID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    makeGetRequest(fmt::format("/pack/{}", packID), {}, std::move(onComplete), std::move(onError));
}

void DSRequest::incrementPackDownload(const std::string& packID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    makeGetRequestWithListener(m_incrementListener, fmt::format("/pack/{}/download", packID), {}, std::move(onComplete), std::move(onError));
}

void DSRequest::incrementSFXDownload(const std::string& sfxID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    makeGetRequestWithListener(m_incrementListener, fmt::format("/sfx/{}/download", sfxID), {}, std::move(onComplete), std::move(onError));
}

void DSRequest::getSFXInfo(const std::string& sfxID, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    makeGetRequest(fmt::format("/sfx/{}", sfxID), {}, std::move(onComplete), std::move(onError));
}

void DSRequest::checkModToken(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::vector<std::pair<std::string, std::string>> params = { {"token", token} };
    makeGetRequest("/mod/check-token", params, std::move(onComplete), std::move(onError));
}

void DSRequest::makeGetRequestWithListener(
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

void DSRequest::makeGetRequest(
    const std::string& endpointFmt,
    const std::vector<std::pair<std::string, std::string>>& queryParams,
    std::function<void(const matjson::Value&)> onComplete,
    std::function<void(const matjson::Value&)> onError
) {
    makeGetRequestWithListener(m_listener, endpointFmt, queryParams, std::move(onComplete), std::move(onError));
}

void DSRequest::uploadSFX(const std::string& filePath, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/uploadSFX";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(60));
    req.header("Authorization", token);
    web::MultipartForm form;
    auto fileResult = form.file("file", filePath);
    if (!fileResult) {
        matjson::Value result = matjson::Value::object();
        result["error"] = "Failed to attach file: " + fileResult.unwrapErr();
        if (onError) onError(result);
        return;
    }
    req.bodyMultipart(form);
    m_listener.spawn(
        req.post(url),
        [onComplete, onError](web::WebResponse value) {
        matjson::Value result = matjson::Value::object();
        result["error"] = "There was an issue processing the request.";
        if (value.ok()) {
            auto jsonOpt = value.json();
            if (jsonOpt.isOk()) {
                result = jsonOpt.unwrap();
                if (onComplete) onComplete(result);
                return;
            } else {
                result["error"] = value.string().unwrap();
                if (onError) onError(result);
            }
        } else {
            result["error"] = "Request failed with code " + std::to_string(value.code());
            if (onError) onError(result);
        }
        }
    );
}

void DSRequest::updateSFX(const std::string& sfxID, const matjson::Value& body, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/sfx/" + sfxID;
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    req.bodyJSON(body);
    m_listener.spawn(
        req.patch(url),
        [onComplete, onError](web::WebResponse value) {
        matjson::Value result = matjson::Value::object();
        result["error"] = "There was an issue processing the request.";
        if (value.ok()) {
            auto jsonOpt = value.json();
            if (jsonOpt.isOk()) {
                result = jsonOpt.unwrap();
                if (onComplete) onComplete(result);
                return;
            } else {
                result["error"] = value.string().unwrap();
                if (onError) onError(result);
            }
        } else {
            result["error"] = "Request failed with code " + std::to_string(value.code());
            if (onError) onError(result);
        }
        }
    );
}

void DSRequest::replaceSFXFile(const std::string& sfxID, const std::string& filePath, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/sfx/" + sfxID + "/replaceFile";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(60));
    req.header("Authorization", token);
    web::MultipartForm form;
    auto fileResult = form.file("file", filePath);
    if (!fileResult) {
        matjson::Value result = matjson::Value::object();
        result["error"] = "Failed to attach file: " + fileResult.unwrapErr();
        if (onError) onError(result);
        return;
    }
    req.bodyMultipart(form);
    m_listener.spawn(
        req.post(url),
        [onComplete, onError](web::WebResponse value) {
        matjson::Value result = matjson::Value::object();
        result["error"] = "There was an issue processing the request.";
        if (value.ok()) {
            auto jsonOpt = value.json();
            if (jsonOpt.isOk()) {
                result = jsonOpt.unwrap();
                if (onComplete) onComplete(result);
                return;
            } else {
                result["error"] = value.string().unwrap();
                if (onError) onError(result);
            }
        } else {
            result["error"] = "Request failed with code " + std::to_string(value.code());
            if (onError) onError(result);
        }
        }
    );
}

void DSRequest::deleteSFX(const std::string& sfxID, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/sfx/" + sfxID;
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    m_listener.spawn(
        req.send("DELETE", url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::viewSFXTagAudit(const std::string& sfxID, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/sfx/" + sfxID + "/tagAudit";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    m_listener.spawn(
        req.get(url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::verifySFXFileExists(const std::string& sfxID, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/sfx/" + sfxID + "/verifyFile";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    m_listener.spawn(
        req.get(url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::macroDeleteMissingFiles(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/macro/deleteMissingFiles";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(60));
    req.header("Authorization", token);
    m_listener.spawn(
        req.post(url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::macroAutoAssignTags(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/macro/autoAssignTags";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(60));
    req.header("Authorization", token);
    m_listener.spawn(
        req.post(url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::macroCalculateLengths(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/macro/calculateLengths";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(60));
    req.header("Authorization", token);
    m_listener.spawn(
        req.post(url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::macroTrimSilence(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/macro/trimSilence";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(60));
    req.header("Authorization", token);
    m_listener.spawn(
        req.post(url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::uploadPack(const matjson::Value& body, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/uploadPack";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(60));
    req.header("Authorization", token);
    req.bodyJSON(body);
    m_listener.spawn(
        req.send("POST", url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::updatePack(const std::string& packID, const matjson::Value& body, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/pack/" + packID;
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    req.bodyJSON(body);
    m_listener.spawn(
        req.send("PATCH", url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::deletePack(const std::string& packID, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/pack/" + packID;
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    m_listener.spawn(
        req.send("DELETE", url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::listUsers(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/users";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    m_listener.spawn(
        req.get(url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::deleteUser(const std::string& userId, const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/users/" + userId;
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    m_listener.spawn(
        req.send("DELETE", url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::getAdminNetworkInfo(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/admin/networkInfo";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    m_listener.spawn(
        req.get(url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}

void DSRequest::resetAdminRateLimit(const std::string& token, std::function<void(const matjson::Value&)> onComplete, std::function<void(const matjson::Value&)> onError) {
    std::string baseUrl = Mod::get()->getSettingValue<std::string>("server-url");
    std::string url = baseUrl + "/api/admin/resetRateLimit";
    auto req = web::WebRequest();
    req.timeout(std::chrono::seconds(30));
    req.header("Authorization", token);
    m_listener.spawn(
        req.post(url),
        [onComplete, onError](web::WebResponse value) {
            matjson::Value result = matjson::Value::object();
            result["error"] = "There was an issue processing the request.";
            if (value.ok()) {
                auto jsonOpt = value.json();
                if (jsonOpt.isOk()) {
                    result = jsonOpt.unwrap();
                    if (onComplete) onComplete(result);
                    return;
                } else {
                    result["error"] = value.string().unwrap();
                    if (onError) onError(result);
                }
            } else {
                result["error"] = "Request failed with code " + std::to_string(value.code());
                if (onError) onError(result);
            }
        }
    );
}
