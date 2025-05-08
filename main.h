//
// Created by hujiayucc on 25-5-4.
//

#ifndef LIBRARY_H
#define LIBRARY_H
#ifdef _WIN32
#ifdef XLZ_EXPORTS
#define XLZ __declspec(dllexport)
#else
#define XLZ __declspec(dllimport)
#endif
#else
#define XLZ
#endif

#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif
    /** 初始化 */
    XLZ const char* appload(const char* apidata, const char* pluginkey);

    /**
     * @brief 滑块验证处理函数
     * @param qq 来源QQ号
     * @param url 滑块验证完整网址
     * @return 验证票据字符串，失败返回空
     * @note 多线程环境运行，失败时需直接返回空值
     */
    XLZ const char* GetTicket(int64_t qq, const char *url);

    /**
     * @brief 短信验证码处理函数
     * @param qq 来源QQ号
     * @param phone 接收短信的手机号（含*遮掩符）
     * @return 短信验证码，失败返回空
     * @note 多线程环境运行，失败时需直接返回空值
     */
    XLZ const char* GetPhoneVefCode(int64_t qq, const char *phone);

    /**
     * @brief 插件启用初始化函数
     * @return 启用响应状态码
     */
    XLZ int32_t AppStart();

    /**
     * @brief 插件禁用处理函数
     * @return 状态码
     * @note 本函数无法使用框架API
     */
    XLZ int32_t AppEnd();

    /**
     * @brief 插件卸载处理函数
     * @return 状态码
     * @note 本函数无法使用框架API
     */
    XLZ int32_t AppUnload();

    /**
     * @brief 插件控制面板处理
     * @return 状态码
     */
    XLZ int32_t ControlPanel();

    /**
     * @brief 私聊消息处理函数
     * @param data_ptr 消息数据结构指针
     * @return 消息处理状态
     * @note 多线程环境运行，返回1阻止后续插件处理
     */
    XLZ int32_t OnPrivate(int32_t data_ptr);

    /**
     * @brief 群聊消息处理函数
     * @param data_ptr 消息数据结构指针
     * @return 消息处理状态
     * @note 多线程环境运行，返回1阻止后续插件处理
     */
    XLZ int32_t OnGroup(int32_t data_ptr);

    /**
     * @brief 频道推送处理函数
     * @param data_ptr 推送数据结构指针
     * @return 消息处理状态
     * @note 多线程环境运行，避免耗时操作
     */
    XLZ int32_t OnGuildPush(int32_t data_ptr);

    /**
     * @brief 插件消息预处理函数
     * @param data_ptr 消息数据结构指针
     * @return 处理后的消息内容
     * @note 多线程环境运行，需处理跨插件消息
     */
    XLZ const char* OnPluginMessage(int32_t data_ptr);

    /**
     * @brief 事件消息处理函数
     * @param data_ptr 事件数据结构指针
     * @return 消息处理状态
     * @note 多线程环境运行，支持多种事件类型
     */
    XLZ int32_t OnEvent(int32_t data_ptr);
#ifdef __cplusplus
}
#endif
#endif