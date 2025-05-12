//
// Created by hujiayucc on 25-5-9.
//

#include <algorithm>
#include <random>
#include <sstream>
#include <utils.h>
#include <windows.h>

const char *ReadConfigItem(
    const std::string &filename,
    const std::string &section,
    const std::string &key,
    const std::string &default_value = ""
) {
    char buffer[4096];
    GetPrivateProfileStringA(
        section.c_str(),
        key.c_str(),
        default_value.c_str(),
        buffer,
        sizeof(buffer),
        filename.c_str()
    );
    const std::string str = buffer;
    return (str.empty() ? default_value : str).c_str();
}

bool WriteConfigItem(
    const std::string& filename,
    const std::string& section,
    const std::string& key,
    const std::string& value
) {
    return WritePrivateProfileStringA(
        section.c_str(),
        key.c_str(),
        value.c_str(),
        filename.c_str()
    );
}

bool str_equal(const char *s1, const char *s2) {
    return strcmp(s1, s2) == 0;
}

int64_t str2ll(const char *num) {
    char *endPtr;
    return _strtoi64(num, &endPtr, 10);
}

int64_t str2ll(const std::string &num) {
    return str2ll(num.c_str());
}

std::string gbk2utf8(const std::string& gbk) {
    int len = MultiByteToWideChar(CP_ACP, 0, gbk.c_str(), -1, nullptr, 0);
    auto* wstr = new wchar_t[len];
    MultiByteToWideChar(CP_ACP, 0, gbk.c_str(), -1, wstr, len);

    len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
    const auto utf8_str = new char[len];
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8_str, len, nullptr, nullptr);

    std::string result(utf8_str);
    delete[] wstr;
    delete[] utf8_str;
    return result;
}

std::string utf82gbk(const std::string& utf8) {
    int len = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, nullptr, 0);
    auto* wstr = new wchar_t[len];
    MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, wstr, len);

    len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
    const auto utf8_str = new char[len];
    WideCharToMultiByte(CP_ACP, 0, wstr, -1, utf8_str, len, nullptr, nullptr);

    std::string result(utf8_str);
    delete[] wstr;
    delete[] utf8_str;
    return result;
}

bool str_contains(const std::string& str1, const std::string& str2) {
    return str1.find(str2) != std::string::npos;
}

bool str_starts_with(const std::string& str1, const std::string& str2) {
    return str1.size() >= str2.size() && str1.compare(0, str2.size(), str2) == 0;
}

std::string toLower(const std::string& s) {
    std::string result(s);
    std::transform(result.begin(), result.end(), result.begin(),
                   [](const unsigned char c) { return std::tolower(c); });
    return result;
}

void replaceAll(std::string& s, const std::string& from, const std::string& to) {
    size_t pos = 0;
    while ((pos = s.find(from, pos)) != std::string::npos) {
        s.replace(pos, from.length(), to);
        pos += to.length();
    }
}

std::string text_get_right(
    const std::string& str,
    const std::string& substr,
    const int start_pos,
    const bool ignore_case,
    const bool forward_search
) {
    std::string replaced_substr = substr;
    replaceAll(replaced_substr, "#引号", "\"");

    if (replaced_substr.empty()) return "";

    size_t found_pos;
    const size_t str_len = str.length();
    const size_t sub_len = replaced_substr.length();

    if (forward_search) {
        const size_t start = start_pos == -1 ? 0 : static_cast<size_t>(start_pos - 1);
        if (start >= str_len) return "";

        if (ignore_case) {
            found_pos = toLower(str).find(toLower(replaced_substr), start);
        } else {
            found_pos = str.find(replaced_substr, start);
        }
    } else {
        size_t start = start_pos == -1 ? std::string::npos : static_cast<size_t>(start_pos - 1);
        if (start != std::string::npos && start >= str_len) start = std::string::npos;

        if (ignore_case) {
            found_pos = toLower(str).rfind(toLower(replaced_substr), start);
        } else {
            found_pos = str.rfind(replaced_substr, start);
        }
    }

    if (found_pos == std::string::npos || found_pos + sub_len > str_len) {
        return "";
    }

    return str.substr(found_pos + sub_len);
}

void replaceSubstrMark(std::string& s) {
    size_t pos = 0;
    const std::string from = "#引号";
    const std::string to = "\"";
    while ((pos = s.find(from, pos)) != std::string::npos) {
        s.replace(pos, from.length(), to);
        pos += to.length();
    }
}

size_t safeStartPos(const int start_pos, const size_t str_len, const bool forward) {
    if (start_pos == -1) {
        return forward ? 0 : std::string::npos;
    }
    const auto pos = static_cast<size_t>(start_pos - 1);
    return pos >= str_len ? (forward ? str_len : std::string::npos) : pos;
}

std::string text_get_left(
    const std::string& str,
    const std::string& substr,
    const int start_pos,
    const bool ignore_case,
    const bool forward_search
) {
    std::string processed_sub = substr;
    replaceSubstrMark(processed_sub);
    if (processed_sub.empty()) return str; // 空子串返回原字符串

    const size_t str_len = str.length();
    if (const size_t sub_len = processed_sub.length(); str_len == 0 || sub_len > str_len) return "";

    const size_t start = safeStartPos(start_pos, str_len, forward_search);

    size_t found_pos;
    if (forward_search) {
        if (ignore_case) {
            std::string lower_str(str);
            std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                          [](const unsigned char c) { return std::tolower(c); });
            std::string lower_sub(processed_sub);
            std::transform(lower_sub.begin(), lower_sub.end(), lower_sub.begin(),
                          [](const unsigned char c) { return std::tolower(c); });
            found_pos = lower_str.find(lower_sub, start);
        } else {
            found_pos = str.find(processed_sub, start);
        }
    } else {
        if (ignore_case) {
            std::string lower_str(str);
            std::transform(lower_str.begin(), lower_str.end(), lower_str.begin(),
                          [](const unsigned char c) { return std::tolower(c); });
            std::string lower_sub(processed_sub);
            std::transform(lower_sub.begin(), lower_sub.end(), lower_sub.begin(),
                          [](const unsigned char c) { return std::tolower(c); });
            found_pos = lower_str.rfind(lower_sub, start);
        } else {
            found_pos = str.rfind(processed_sub, start);
        }
    }

    if (found_pos == std::string::npos) {
        return str;
    }

    return str.substr(0, found_pos);
}

int32_t GetRandom(const int32_t min, const int32_t max) {
    thread_local std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution distrib(min, max);
    return distrib(gen);
}

std::vector<std::string> splitString(const std::string& s, const char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}
