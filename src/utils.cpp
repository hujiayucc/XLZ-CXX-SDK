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

inline bool strequal(const char *s1, const char *s2) {
    return strcmp(s1, s2) == 0;
}