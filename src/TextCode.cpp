//
// Created by hujiayucc on 25-5-9.
//

#include <TextCode.h>

std::string TextCode::audioLocal(const std::string& filePath, const int voiceType = 0,
                                 const std::string& textContent = "", const int duration = 0) {
    std::ostringstream oss;
    oss << "[AudioFile,path=" << filePath
        << ",type=" << voiceType
        << ",content=" << textContent
        << ",time=" << duration << "]";
    return oss.str();
}

std::string TextCode::smallBeanEmoji(const int id) {
    return "[bq" + std::to_string(id) + "]";
}

std::string TextCode::largeEmoji(const int emojiId, const std::string& emojiName,
                                 const std::string& hashValue, const std::string& flagValue) {
    std::ostringstream oss;
    oss << "[bigFace,Id=" << emojiId
        << ",name=" << emojiName
        << ",hash=" << hashValue
        << ",flag=" << flagValue << "]";
    return oss.str();
}

std::string TextCode::smallFaceEmoji(const int faceId, const std::string& faceName) {
    return "[smallFace,name=" + faceName + ",Id=" + std::to_string(faceId) + "]";
}

std::string TextCode::standardEmoji(const int faceId, const std::string& faceName) {
    return "[Face,Id=" + std::to_string(faceId) + ",name=" + faceName + "]";
}

std::string TextCode::atUser(const long long targetId, const bool addSpace = false) {
    return addSpace ? "[@" + std::to_string(targetId) + "] "
                   : "[@" + std::to_string(targetId) + "]";
}

std::string TextCode::atAll() {
    return "[@all]";
}

std::string TextCode::imageLocal(const std::string& filePath, const int width = 0, const int height = 0,
                          const bool isAnimated = false, const std::string& previewText = "") {
    std::ostringstream oss;
    oss << "[picFile,path=" << filePath
        << ",wide=" << width
        << ",high=" << height
        << ",cartoon=" << (isAnimated ? "true" : "false")
        << ",str=" << previewText << "]";
    return oss.str();
}

std::string TextCode::replyMessage(const std::string& originalContent, const long long senderId,
                            const int timestamp, const int requestId, const long long randomSeed) {
    std::ostringstream oss;
    oss << "[Reply,Content=" << utf8ToUsc2(originalContent)
        << ",SendQQID=" << senderId
        << ",Req=" << requestId
        << ",Random=" << randomSeed
        << ",SendTime=" << timestamp << "]";
    return oss.str();
}

std::string TextCode::utf8ToUsc2(const std::string& utf8) {
    const int wlen = MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, nullptr, 0);
    auto* wstr = new wchar_t[wlen];
    MultiByteToWideChar(CP_UTF8, 0, utf8.c_str(), -1, wstr, wlen);

    std::string result(reinterpret_cast<char*>(wstr), wlen * sizeof(wchar_t));
    delete[] wstr;
    return result;
}

std::string TextCode::usc2ToUtf8(const std::string& usc2) {
    const auto* wstr = reinterpret_cast<const wchar_t*>(usc2.data());
    const int utf8_len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
    char* utf8_str = new char[utf8_len];
    WideCharToMultiByte(CP_UTF8, 0, wstr, -1, utf8_str, utf8_len, nullptr, nullptr);

    std::string result(utf8_str);
    delete[] utf8_str;
    return result;
}