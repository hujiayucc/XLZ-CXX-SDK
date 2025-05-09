//
// Created by hujiayucc on 25-5-4.
//

#include "main.h"

#include <appinfo.h>
#include <constant.h>
#include <global.h>
#include <LocalConfig.h>
#include <MessageTools.h>
#include <windows.h>

#include "utils.h"

XLZ const char *appload(const char *apidata, const char *pluginkey) {
    Api.init(apidata, pluginkey);
    auto appInfo = ApplicationInfo();
    appInfo.SetAppName("C++ Sample Plugin");
    appInfo.SetAuthor("hujiayucc");
    appInfo.SetVersion("1.0.0");
    appInfo.SetDescription("C++模板插件\nC++ Sample Plugin");
    appInfo.AddAllPermissions("测试");
    // appInfo.SetTicketHandler(&GetTicket);
    // appInfo.SetSMSHandler(&GetPhoneVefCode);
    appInfo.SetEnableHandler(&AppStart);
    appInfo.SetDisableHandler(&AppEnd);
    appInfo.SetUninstallHandler(&AppUnload);
    appInfo.SetSettingsHandler(&ControlPanel);
    appInfo.SetPrivateMsgHandler(&OnPrivate);
    appInfo.SetGroupMsgHandler(&OnGroup);
    // appInfo.SetChannelHandler(&OnGuildPush);
    // appInfo.SetEventHandler(&OnEvent);
    // appInfo.SetOutputFilter(&OnPluginMessage);
    return appInfo.GetData();
}

XLZ const char* GetTicket(int64_t qq, const char *url) {
    // 插件优先级取决于事件消息处理优先级
    // 弹窗时需在标题注明插件来源
    return ""; // 失败返回空值
}

XLZ const char* GetPhoneVefCode(int64_t qq, const char *phone) {
    // 插件优先级取决于事件消息处理优先级
    // 弹窗时需在标题注明插件来源
    return ""; // 失败返回空值
}

XLZ int32_t AppStart() {
    PLUGIN_DATA_DIR = Api.GetPluginDataDir();
    MessageBox(nullptr, Api.GetPluginDataDir(), "测试", MB_OK);
    Api.OutLog("日志输出测试");
    return ENABLE_RESPONSE_SUCCESS;
}

XLZ int32_t AppEnd() {
    return 0;
}

XLZ int32_t AppUnload() {
    return 0;
}

XLZ int32_t ControlPanel() {
    try {
        char *endPtr;
        char *endPtr2;
        const char *test = ReadConfigItem(
            std::string(PLUGIN_DATA_DIR) + "test.ini",
            "Test", "number", "0"
        );
        const bool test2 = WriteConfigItem(
            std::string(PLUGIN_DATA_DIR) + "test.ini",
            "Test", "number", std::to_string(strtol(test, &endPtr, 10) + 1)
        );
        const char *test3 = ReadConfigItem(
            std::string(PLUGIN_DATA_DIR) + "测试.ini",
            "Test", "number", "0"
        );
        const bool test4 = WriteConfigItem(
            std::string(PLUGIN_DATA_DIR) + "测试.ini",
            "测试", "次数", std::to_string(strtol(test3, &endPtr2, 10) + 1)
        );
        if (test2 && test4) {
            MessageBox(nullptr, "配置写入成功", "提示", MB_OK);
        } else {
            MessageBox(nullptr, "配置写入失败", "提示", MB_OK);
        }
    } catch (std::exception &e) {
        MessageBox(nullptr, (std::string("发生错误\n") + e.what()).c_str(), "错误提示", MB_OK);
    }
    return 0;
}

XLZ int32_t OnPrivate(const int32_t data_ptr) {
    PrivateMessageData data{};
    MessageTools::ReadPrivateMessage(data_ptr, data);
    if (data.msgType == MSG_TYPE_FRIEND_NORMAL && data.senderQQ == 2792607647 && strequal(data.content, "C++ Test")) {
        Api.OutLog(data.senderQQ == 2792607647 ? "True" : "False");
        Api.SendPrivateMessage(BOT_QQ, data.senderQQ, "C++模板插件已运行！\nC++ Sample Plugin Is Running!");
        return MSG_INTERCEPT;
    }
    return MSG_CONTINUE;
}

XLZ int OnGroup(const int32_t data_ptr) {
    GroupMessageData data{};
    MessageTools::ReadGroupMessage(data_ptr, data);
    if (data.senderQQ == 2792607647 && strequal(data.content, "C++ Test")) {
        Api.OutLog(data.senderQQ == 2792607647 ? "True" : "False");
        Api.SendGroupMessage(BOT_QQ, data.groupNumber, "C++模板插件已运行！\nC++ Sample Plugin Is Running!");
        return MSG_INTERCEPT;
    }
    return MSG_CONTINUE;
}

XLZ int32_t OnGuildPush(const int32_t data_ptr) {
    return MSG_CONTINUE; // #消息处理_忽略
}

XLZ const char* OnPluginMessage(const int32_t data_ptr) {
    return ""; // 返回原始内容
}

XLZ int32_t OnEvent(const int32_t data_ptr) {
    // 事件类型分支处理
    // 示例好友事件处理
    /*
    switch(data.type) {
    case 好友事件_签名变更:
        // 处理签名变更逻辑
        break;
    case 好友事件_被好友删除:
        // 处理删除好友逻辑
        break;
    // 其他事件处理...
    }
    */
    return MSG_CONTINUE; // #消息处理_忽略
}
