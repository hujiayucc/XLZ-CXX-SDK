//
// Created by hujia on yucc25-5-9.
//

#include <MessageTools.h>

void MessageTools::ReadPrivateMessage(const int dataPointer, PrivateMessageData& data) {
    memcpy(&data, reinterpret_cast<PrivateMessageData*>(dataPointer), sizeof(PrivateMessageData));
}

void MessageTools::ReadGroupMessage(const int dataPointer, GroupMessageData& data) {
    memcpy(&data, reinterpret_cast<GroupMessageData*>(dataPointer), sizeof(GroupMessageData));
}

void MessageTools::NormalizeNewlines(std::string& messageContent) {
    ReplaceAll(messageContent, "\r\n", "\r\n");  // 标准换行
    ReplaceAll(messageContent, "\n", "\r\n");    // LF替换
    ReplaceAll(messageContent, "\r", "\r\n");    // CR替换
}

std::string MessageTools::GetTencentNewline(const bool isAndroid = false) {
    return isAndroid ? "\n" : "\r";
}

ULONG MessageTools::ReleaseComInterface(IUnknown* pInterface) {
    return pInterface ? pInterface->Release() : 0;
}

void MessageTools::ReplaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}