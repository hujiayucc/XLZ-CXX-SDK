//
// Created by hujiayucc on 25-5-9.
//

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
    auto utf8_str = new char[len];
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8_str, len, nullptr, nullptr);

    std::string result(utf8_str);
    delete[] wstr;
    delete[] utf8_str;
    return result;
}

bool str_contains(const std::string& str1, const std::string& str2) {
    return str1.find(str2) != std::string::npos;
}