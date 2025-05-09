//
// Created by hujiayucc on 25-5-9.
//

#include <api.h>
#include <data.h>
#include <func.h>
#include <utils.h>

int API::GetFunctionAddress(const std::string &functionName) const {
    return apidata[gbk2utf8(functionName)];
}

const char *API::OutLog(
    const char *message,
    const std::optional<int> textColor,
    const std::optional<int> bgColor
) const {
    const int relTextColor = textColor.value_or(32768);
    const int relBGColor = bgColor.value_or(16777215);
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("输出日志"));
        return static_cast<char *>(func(pluginkey.c_str(), message, relTextColor, relBGColor));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

const char *API::SendPrivateMessage(const int64_t fQq, const int64_t qq, const char *message, int64_t *random, int64_t *req) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("发送好友消息"));
        return static_cast<char *>(func(pluginkey.c_str(), fQq, qq, message, &random, &req));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

const char *API::SendGroupMessage(const int64_t fQq, const int64_t group, const char *message, int64_t *random, int64_t *req) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("发送群消息"));
        return static_cast<char *>(func(pluginkey.c_str(), fQq, group, message, &random, &req));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

const char *API::GetPluginDataDir() const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("取插件数据目录"));
        return static_cast<char *>(func(pluginkey.c_str()));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

void API::rebootFamework() const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("框架重启"));
        func(pluginkey.c_str());
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}


void API::reload(std::string path = "") const {
    if (path.empty()) path = "empty";
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("重载自身"));
        func(pluginkey.c_str(), path.c_str());
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

const char *API::QQLike(const int64_t fQq, const int64_t qq) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("QQ点赞"));
        return static_cast<char *>(func(pluginkey.c_str(), fQq, qq));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}


const char *API::GroupLuckyRedPacket(
    const int64_t fQq, const int32_t total, const int32_t totalAmount,
    const int64_t group, const char *bless, const char *payPasswd,
    const int32_t skinId, const int32_t bankCard, const CaptchaInfo *verInfo
) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("群聊拼手气红包"));
        return static_cast<char *>(func(
            pluginkey.c_str(), fQq, total, totalAmount, group,
            bless, skinId, payPasswd, bankCard, &verInfo
        ));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

const char *API::GroupVoiceRedPacket(
    const int64_t fQq, const int32_t total, const int32_t totalAmount, const int64_t group,
    const char *voiceText, const char *payPasswd, const int32_t bankCard, const CaptchaInfo *verInfo
) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("群聊语音红包"));
        return static_cast<char *>(func(
            pluginkey.c_str(), fQq, total, totalAmount, group,
            voiceText, payPasswd, bankCard, &verInfo
        ));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

const char *API::GroupExclusiveRedPacket(
    const int64_t fQq, const int32_t total, const int32_t totalAmount, const int64_t group,
    const char *qq, const char *bless, const bool sharing, const char *payPasswd,
    const int32_t bankCard, const CaptchaInfo *verInfo
) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("群聊专属红包"));
        return static_cast<char *>(func(
            pluginkey.c_str(), fQq, total, totalAmount, group, qq,
            bless, sharing, payPasswd, bankCard, &verInfo
        ));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}