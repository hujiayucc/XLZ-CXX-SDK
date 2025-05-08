//
// Created by hujiayucc on 25-5-7.
//

#ifndef API_H
#define API_H

#include "func.h"
#include <string>
#include <algorithm>
#include <optional>
#include <shlwapi.h>
#include <stdexcept>

class API {
    std::string pluginkey;
    std::string apidata;

    /**
     * @brief 不区分大小写的字符比较
     * @param a 第一个字符
     * @param b 第二个字符
     * @return 是否相等（忽略大小写）
     */
    static bool ichar_equals(char a, char b);

    /**
     * @brief 安全查找子字符串位置
     * @param haystack 主文本
     * @param needle 查找文本
     * @param start 起始位置
     * @param caseSensitive 是否区分大小写
     * @return 找到的位置或std::string::nos
     */
    static size_t safe_find(const std::string &haystack, const std::string &needle, size_t start, bool caseSensitive);

    /**
     * @brief 提取两个标记之间的文本
     * @param source 源文本
     * @param front 前导标记（支持#quote转义）
     * @param back 后缀标记（支持#quote转义）
     * @param startPos 起始搜索位置（默认0）
     * @param caseSensitive 是否区分大小写（默认true）
     * @return 提取到的中间文本，失败返回空字符串
     *
     * @example
     * std::string result = ExtractMiddleText(
     *     "Hello <tag>World</tag>",
     *     "<tag>",
     *     "</tag>"
     * ); // 返回 "World"
     */
    std::string ExtractMiddleText(
        const std::string &source,
        const std::string &front,
        const std::string &back,
        size_t startPos,
        bool caseSensitive
    );

    /**
     * @brief 获取API函数地址
     * @param functionName 目标函数名
     * @return 函数地址，失败返回0
     */
    int GetFunctionAddress(const std::string &functionName) const;

public:
    API() = default;

    void init(std::string apidata, std::string pluginkey) {
        this->pluginkey = std::move(pluginkey);
        this->apidata = std::move(apidata);
    }

    /**
     * @brief 日志输出函数
     * @param message 日志内容
     * @param textColor 文字颜色（可选）
     * @param bgColor 背景颜色（可选）
     * @return 操作结果
     */
    const char *OutLog(
        const char *message,
        std::optional<int> textColor = std::nullopt,
        std::optional<int> bgColor = std::nullopt
    ) const;

    /**
     * @brief 发送好友消息
     * @param fQq 框架QQ
     * @param qq 好友QQ
     * @param message 消息内容
     * @param random 撤回消息用（可选）
     * @param req 撤回消息用（可选）
     * @return 成功返回的time用于撤回消息
     */
    const char *SendPrivateMessage(
        int64_t fQq,
        int64_t qq,
        const char *message,
        int64_t *random = nullptr,
        int64_t *req = nullptr
    ) const;

    /**
     * @brief 发送群消息
     * @param fQq 框架QQ
     * @param group QQ群号
     * @param message 消息内容
     * @param random 撤回消息用（可选）
     * @param req 撤回消息用（可选）
     * @return 成功返回的time用于撤回消息
     */
    const char *SendGroupMessage(
        int64_t fQq,
        int64_t group,
        const char *message,
        int64_t *random = nullptr,
        int64_t *req = nullptr
    ) const;
};
#endif
inline bool ichar_equals(const char a, const char b) {
    return std::tolower(static_cast<unsigned char>(a)) ==
           std::tolower(static_cast<unsigned char>(b));
}

inline size_t safe_find(const std::string &haystack,
                        const std::string &needle,
                        const size_t start = 0,
                        const bool caseSensitive = true) {
    if (start >= haystack.length() || needle.empty()) {
        return std::string::npos;
    }

    const auto it = std::search(
        haystack.begin() + start, haystack.end(),
        needle.begin(), needle.end(),
        caseSensitive ? [](const char a, const char b) { return a == b; } : ichar_equals
    );

    return it == haystack.end() ? std::string::npos : std::distance(haystack.begin(), it);
}

inline std::string ExtractMiddleText(
    const std::string &source,
    const std::string &front,
    const std::string &back,
    const size_t startPos = 0,
    const bool caseSensitive = true
) {
    // 替换转义字符
    auto replace_quotes = [](std::string s) {
        size_t pos = 0;
        const std::string target = "#引号";
        while ((pos = s.find(target, pos)) != std::string::npos) {
            s.replace(pos, target.length(), "\"");
            pos += 1; // 替换后移动位置
        }
        return s;
    };

    // 处理转义字符
    const std::string processedFront = replace_quotes(front);
    const std::string processedBack = replace_quotes(back);

    // 查找前导标记
    const size_t frontPos = safe_find(source, processedFront, startPos, caseSensitive);
    if (frontPos == std::string::npos) return "";

    // 计算内容起始位置
    const size_t contentStart = frontPos + processedFront.length();
    if (contentStart > source.length()) return "";

    // 查找后缀标记
    const size_t backPos = safe_find(
        source,
        processedBack,
        contentStart,
        caseSensitive
    );
    if (backPos == std::string::npos || backPos < contentStart) return "";

    // 提取中间内容
    return source.substr(contentStart, backPos - contentStart);
}

inline int API::GetFunctionAddress(const std::string &functionName) const {
    const std::string startPattern = "\"" + functionName + "\":";
    const size_t startPos = apidata.find(startPattern);

    if (startPos == std::string::npos) return 0;
    const size_t valueStart = startPos + startPattern.length();
    const size_t commaPos = apidata.find(',', valueStart);
    const size_t bracePos = apidata.find('}', valueStart);

    size_t endPos = std::string::npos;
    if (commaPos != std::string::npos) endPos = commaPos;
    if (bracePos != std::string::npos) {
        if (endPos == std::string::npos || bracePos < endPos) {
            endPos = bracePos;
        }
    }

    if (endPos == std::string::npos) {
        return 0;
    }

    // 提取地址字符串
    const std::string addressStr = apidata.substr(valueStart, endPos - valueStart);

    // 转换为整数地址
    char *endPtr;

    return strtoul(addressStr.c_str(), &endPtr, 10);
}

inline const char *API::OutLog(
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

inline const char *API::SendPrivateMessage(const int64_t fQq, const int64_t qq, const char *message, int64_t *random,
                                           int64_t *req) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("发送好友消息"));
        return static_cast<char *>(func(pluginkey.c_str(), fQq, qq, message, &random, &req));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

inline const char *API::SendGroupMessage(const int64_t fQq, const int64_t group, const char *message, int64_t *random,
                                         int64_t *req) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("发送群消息"));
        return static_cast<char *>(func(pluginkey.c_str(), fQq, group, message, &random, &req));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}
