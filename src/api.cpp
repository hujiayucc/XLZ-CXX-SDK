//
// Created by hujiayucc on 25-5-9.
//

#include <api.h>

bool ichar_equals(const char a, const char b) {
    return std::tolower(static_cast<unsigned char>(a)) ==
           std::tolower(static_cast<unsigned char>(b));
}

size_t safe_find(const std::string &haystack,
                        const std::string &needle,
                        const size_t start = 0,
                        const bool caseSensitive = true) {
    if (start >= haystack.length() || needle.empty()) {
        return std::string::npos;
    }

    const auto it = std::search(
        haystack.begin() + start, haystack.end(), // NOLINT(*-narrowing-conversions)
        needle.begin(), needle.end(),
        caseSensitive ? [](const char a, const char b) { return a == b; } : ichar_equals
    );

    return it == haystack.end() ? std::string::npos : std::distance(haystack.begin(), it);
}

std::string ExtractMiddleText(
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

int API::GetFunctionAddress(const std::string &functionName) const {
    const std::string startPattern = "\"" + functionName + "\":";
    const size_t startPos = apidata.find(startPattern);

    if (startPos == std::string::npos) return 0ul;
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
        return 0ul;
    }

    // 提取地址字符串
    const std::string addressStr = apidata.substr(valueStart, endPos - valueStart);

    // 转换为整数地址
    char *endPtr;

    return strtoul(addressStr.c_str(), &endPtr, 10);
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

const char *API::SendPrivateMessage(const int64_t fQq, const int64_t qq, const char *message, int64_t *random,
                                           int64_t *req) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("发送好友消息"));
        return static_cast<char *>(func(pluginkey.c_str(), fQq, qq, message, &random, &req));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}

const char *API::SendGroupMessage(const int64_t fQq, const int64_t group, const char *message, int64_t *random,
                                         int64_t *req) const {
    try {
        const auto func = reinterpret_cast<Func>(GetFunctionAddress("发送群消息"));
        return static_cast<char *>(func(pluginkey.c_str(), fQq, group, message, &random, &req));
    } catch (std::exception &e) {
        throw std::runtime_error(e.what());
    }
}