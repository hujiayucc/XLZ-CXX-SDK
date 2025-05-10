//
// Created by hujiayucc on 25-5-4.
//

#pragma once
#include <cstdio>
#include <windows.h>
#include <api.h>
#include <utils.h>

const char *OutLog(
    const char *message,
    const std::optional<int> textColor = std::nullopt,
    const std::optional<int> bgColor = std::nullopt
) {
    const int relTextColor = textColor.value_or(32768);
    const int relBGColor = bgColor.value_or(16777215);
    printf("[%s] %s\n", "XLZ", message);
    return "success";
}

int main()
{
    const HMODULE hModule = LoadLibraryA("XLZ.dll");
    if (!hModule) {
        printf("[Error] DLL load failed. Error code: %d\n", GetLastError());
        return -1;
    }

    printf("OutLog Ptr: %p\n", &OutLog);
    try {
        auto api = API();
        api.init(
            nlohmann::json::parse(gbk2utf8(
            "{\"输出日志\":" + std::to_string(reinterpret_cast<int>(&OutLog)) + "}")),
            ""
        );
        const char *result = api.OutLog("Hello, World!\n");
        printf("OutLog Result: %s\n", result);
    } catch (std::exception &e) {
        MessageBoxA(nullptr, e.what(), "Error", MB_OK);
    }

    FreeLibrary(hModule);

    auto text = "Hello World";
    auto text2 = "Hello";
    if (str_contains(text, text2)) {
        printf("Text contains text2\n");
    }

    if (str_equal(text, text)) {
        printf("Text equal text\n");
    }
    return 0;
}