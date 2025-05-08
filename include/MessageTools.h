//
// Created by hujiayucc on 25-5-7.
//

#ifndef MESSAGETOOLS_H
#define MESSAGETOOLS_H

#include <string>
#include "data.h"
#include "TextCode.h"

class MessageTools {
public:
    /**
     * @brief 读取私聊消息数据到结构体
     * @param[in] dataPointer 原始数据内存指针
     * @param[out] data 输出数据结构体引用
     */
    static void ReadPrivateMessage(int dataPointer, PrivateMessageData& data);

    /**
     * @brief 读取群消息数据到结构体
     * @param[in] dataPointer 原始数据内存指针
     * @param[out] data 输出数据结构体引用
     */
    static void ReadGroupMessage(int dataPointer, GroupMessageData& data);

    /**
     * @brief 统一处理消息中的换行符
     * @param[in,out] messageContent 需要处理的消息内容（引用传参）
     * @note 将各种换行符统一替换为\r\n格式
     */
    static void NormalizeNewlines(std::string& messageContent);

    /**
     * @brief 获取腾讯系应用换行符
     * @param[in] isAndroid 是否安卓平台
     * @return 对应平台的换行符字符串
     * @note PC端使用CR(\r)，移动端使用LF(\n)
     */
    static std::string GetTencentNewline(bool isAndroid);

    /**
     * @brief 释放COM接口引用
     * @param[in] pInterface 需要释放的接口指针
     * @return 释放后的引用计数
     */
    static ULONG ReleaseComInterface(IUnknown* pInterface);

private:
    /// 字符串替换辅助函数
    static void ReplaceAll(std::string& str, const std::string& from, const std::string& to);
};
#endif
