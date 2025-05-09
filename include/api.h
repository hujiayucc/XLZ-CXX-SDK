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

    /** 取插件数据目录 */
    const char *GetPluginDataDir() const;
};
#endif