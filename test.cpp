//
// Created by hujiayucc on 25-5-4.
//

#pragma once
#include <cstdio>
#include <windows.h>

typedef void(__stdcall *init)();

int main()
{
    const HMODULE hModule = LoadLibraryA("XLZ.dll");
    if (!hModule) {
        printf("[Error] DLL load failed. Error code: %d\n", GetLastError());
        return -1;
    }

    const auto apiOut = reinterpret_cast<init>(GetProcAddress(hModule, "apprun"));

    if (apiOut == nullptr) {
        printf("[Error] Function not found. Error code: %d\n", GetLastError());
        FreeLibrary(hModule);
        return -1;
    }

    apiOut();

    FreeLibrary(hModule);
    return 0;
}