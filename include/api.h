//
// Created by hujiayucc on 25-5-7.
//

#ifndef API_H
#define API_H

#include <string>
#include <algorithm>
#include <data.h>
#include <optional>
#include <stdexcept>
#include <nlohmann/json.hpp>

class API {
    std::string pluginkey;
    nlohmann::json apidata;

    /**
     * @brief 获取API函数地址
     * @param functionName 目标函数名
     * @return 函数地址，失败返回0
     */
    [[nodiscard]] int GetFunctionAddress(const std::string &functionName) const;

public:
    API() = default;

    void init(const nlohmann::json &apidata, std::string pluginkey) {
        this->pluginkey = std::move(pluginkey);
        this->apidata = apidata;
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
    [[nodiscard]] const char *GetPluginDataDir() const;

    /** 框架重启 */
    void rebootFamework() const;

    /**
     * 重载自身插件
     * @param path 新文件路径
     */
    void reload(std::string path) const;

    /**
     * @brief QQ点赞
     * @param fQq 框架QQ
     * @param qq 对方QQ
     * @return 点赞结果
     */
    [[nodiscard]] const char *QQLike(int64_t fQq, int64_t qq) const;

    /**
     * @brief 群聊拼手气红包
     * @param fQq 框架QQ
     * @param total 总数
     * @param totalAmount 总金额，单位分
     * @param group QQ群号
     * @param bless 祝福语，支持emoji
     * @param skinId 红包皮肤ID，1522光与夜之恋,1527代号:三国(打了一辈子仗),1525街霸:对决,1518代号:三国(俺送红包来了),1476天涯明月刀,1512一人之下。其他皮肤id自己找
     * @param payPasswd 支付密码
     * @param bankCard 银行卡序列。大于0时使用银行卡支付
     * @param verInfo 验证码信息，银行卡支付时，若需要短信验证码，将在此传回验证码信息
     * @return 红包发送结果
     */
    const char *GroupLuckyRedPacket(
        int64_t fQq,
        int32_t total,
        int32_t totalAmount,
        int64_t group,
        const char *bless,
        const char *payPasswd,
        int32_t skinId = 0,
        int32_t bankCard = 0,
        const CaptchaInfo *verInfo = nullptr
    ) const;

    /**
     * @brief 群聊语音红包
     * @param fQq 框架QQ
     * @param total 总数
     * @param totalAmount 总金额，单位分
     * @param group QQ群号
     * @param voiceText 语音口令，支持emoji
     * @param payPasswd 支付密码
     * @param bankCard 银行卡序列。大于0时使用银行卡支付
     * @param verInfo 验证码信息，银行卡支付时，若需要短信验证码，将在此传回验证码信息
     * @return 红包发送结果
     */
    const char *GroupVoiceRedPacket(
        int64_t fQq,
        int32_t total,
        int32_t totalAmount,
        int64_t group,
        const char *voiceText,
        const char *payPasswd,
        int32_t bankCard = 0,
        const CaptchaInfo *verInfo = nullptr
    ) const;

    /**
     * @brief 群聊专属红包
     * @param fQq 框架QQ
     * @param total 总数
     * @param totalAmount 总金额，单位分
     * @param group QQ群号
     * @param qq 领取人QQ
     * @param bless 祝福语，支持emoji
     * @param sharing 是否均分
     * @param payPasswd 支付密码
     * @param bankCard 银行卡序列。大于0时使用银行卡支付
     * @param verInfo 验证码信息，银行卡支付时，若需要短信验证码，将在此传回验证码信息
     * @return 红包发送结果
     */
    const char *GroupExclusiveRedPacket(
        int64_t fQq,
        int32_t total,
        int32_t totalAmount,
        int64_t group,
        const char *qq,
        const char *bless,
        bool sharing,
        const char *payPasswd,
        int32_t bankCard = 0,
        const CaptchaInfo *verInfo = nullptr
    ) const;
};
#endif