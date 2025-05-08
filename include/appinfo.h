//
// Created by hujiayucc on 25-5-6.
//

#ifndef APPINFO_H
#define APPINFO_H

#pragma once
#include <vector>
#include <string>
#include <sstream>

class ApplicationInfo {
    int _cnt = 11;
    int _cnt_info = 3;
    int _cnt_Apis = 385;
    std::vector<int> _addres;
    std::vector<std::string> _args;
    std::vector<std::string> _infos;
    std::vector<std::string> Api_names;
    std::string _currentAppName;
    std::ostringstream Applications;
    static std::string EscapeString(const std::string &input);
    static void ProcessAppName(std::string &appName);

public:
    /**
     * @brief 构造函数，初始化数组和预设数据
     * @note 初始化_args和Api_names的预设内容，需与易语言原版数据对齐
     */
    ApplicationInfo();

    /**
     * @brief 设置应用名称（自动过滤非法字符）
     * @param appName 原始应用名称
     * @warning 名称将进行安全过滤，包含非法字符会被移除
     */
    void SetAppName(const std::string &appName);

    /**
     * @brief 设置应用开发者信息
     * @param author 开发者名称（支持转义字符）
     */
    void SetAuthor(const std::string &author) { _infos[0] = EscapeString(author); }

    /**
     * @brief 设置应用版本号
     * @param version 版本号字符串（格式：x.x.x）
     */
    void SetVersion(const std::string &version) { _infos[1] = EscapeString(version); }

    /**
     * @brief 设置应用功能描述
     * @param desc 描述文本（支持转义字符）
     */
    void SetDescription(const std::string &desc) { _infos[2] = EscapeString(desc); }

    /**
     * @brief 添加单个API权限申请
     * @param permission API权限ID（从1开始计数）
     * @param reason 申请理由描述
     * @note 仅当权限ID有效且对应API名称非空时生效
     */
    void AddPermissionRequest(int permission, const std::string &reason);

    /**
     * @brief 批量添加API权限申请
     * @param permissions 权限ID列表
     * @param reason 统一申请理由
     */
    void AddMultiplePermissions(const std::vector<int> &permissions, const std::string &reason);

    /**
     * @brief 申请全部API权限（测试用）
     * @param reason 统一申请理由
     * @warning 生产环境慎用，需遵循最小权限原则
     */
    void AddAllPermissions(const std::string &reason);

    /**
     * @brief 生成最终JSON格式数据
     * @return 符合框架要求的完整JSON字符串
     * @note 包含SDK版本、应用信息、处理函数地址及权限申请列表
     */
    const char *GetData() const;

    /**
     * @brief 设置滑块验证处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetTicketHandler(void* function) { _addres[0] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置短信验证码处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetSMSHandler(void* function) { _addres[1] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置插件启用处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetEnableHandler(void* function) { _addres[2] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置插件禁用处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetDisableHandler(void* function) { _addres[3] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置卸载预处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetUninstallHandler(void* function) { _addres[4] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置插件设置点击处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetSettingsHandler(void* function) { _addres[5] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置私聊消息处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetPrivateMsgHandler(void* function) { _addres[6] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置群消息处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetGroupMsgHandler(void* function) { _addres[7] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置频道事件处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetChannelHandler(void* function) { _addres[8] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置系统事件处理函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetEventHandler(void* function) { _addres[9] = reinterpret_cast<int>(function); }

    /**
     * @brief 设置消息输出拦截函数
     * @param function 函数指针（需转换为整数地址）
     */
    void SetOutputFilter(void* function) { _addres[10] = reinterpret_cast<int>(function); }
};
#endif