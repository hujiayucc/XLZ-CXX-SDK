//
// Created by hujiayucc on 25-5-9.
//

#include <appinfo.h>
#include <constant.h>

ApplicationInfo::ApplicationInfo() {
    // 初始化数组
    _addres.resize(_cnt, 0);
    _args = {
        "author", // 0: 作者信息
        "appv", // 1: 版本信息
        "describe", // 2: 描述信息
        "getticketaddres", // 3: _addres[0] 滑块处理
        "getvefcodeaddres", // 4: _addres[1] 验证码处理
        "useproaddres", // 5: _addres[2] 启用处理
        "banproaddres", // 6: _addres[3] 禁用处理
        "unitproaddres", // 7: _addres[4] 卸载处理
        "setproaddres", // 8: _addres[5] 设置处理
        "friendmsaddres", // 9: _addres[6] 私聊处理
        "groupmsaddres", // 10: _addres[7] 群消息处理
        "ChannelFunc", // 11: _addres[8] 频道处理
        "eventmsaddres", // 12: _addres[9] 事件处理
        "PmDealFunc" // 13: _addres[10] 输出过滤
    };
    _infos.resize(_cnt_info);
    Api_names = {
        "输出日志", "发送好友消息", "发送群消息", "发送群临时消息", "", "", "删除好友", "置屏蔽好友", "置特别关心好友", "", "", "", "", "上传好友图片", "上传群图片",
        "上传好友语音", "上传群语音", "上传头像", "设置群名片", "取昵称_从缓存", "强制取昵称", "获取skey", "获取pskey", "获取clientkey", "取框架QQ", "取好友列表",
        "取群列表", "取群成员列表", "设置管理员", "取管理层列表", "取群名片", "取个性签名", "修改昵称", "修改个性签名", "删除群成员", "禁言群成员", "退群", "解散群", "上传群头像",
        "全员禁言", "群权限_发起新的群聊", "群权限_发起临时会话", "群权限_上传文件", "群权限_上传相册", "群权限_邀请好友加群", "群权限_匿名聊天", "群权限_坦白说",
        "群权限_新成员查看历史消息", "群权限_邀请方式设置", "撤回消息_群聊", "撤回消息_私聊本身", "", "", "是否被禁言", "处理好友验证事件", "处理群验证事件", "", "上传群文件",
        "创建群文件夹", "设置在线状态", "QQ点赞", "取图片下载地址", "查询好友信息", "查询群信息", "框架重启", "群文件转发至群", "群文件转发至好友", "好友文件转发至好友", "置群消息接收",
        "取群名称_从缓存", "取好友在线状态", "取QQ钱包个人信息", "获取订单详情", "", "分享音乐", "更改群聊消息内容", "更改私聊消息内容", "", "", "", "", "", "", "",
        "", "", "", "", "", "重命名群文件夹", "删除群文件夹", "删除群文件", "保存文件到微云", "移动群文件", "取群文件列表", "设置专属头衔", "下线指定QQ", "登录指定QQ",
        "", "发送输入状态", "", "打好友电话", "取群文件下载地址", "头像双击_好友", "头像双击_群", "取群成员简略信息", "群聊置顶", "私聊置顶", "取加群链接", "设为精华",
        "群权限_设置群昵称规则", "群权限_设置群发言频率", "群权限_设置群查找方式", "", "置群内消息通知", "修改群名称", "", "登录网页取ck", "发送群公告", "取群成员信息", "",
        "取群网页cookie", "", "取收款链接", "取群小视频下载地址", "取私聊小视频下载地址", "上传小视频", "取群成员概况", "", "", "", "置群聊备注", "", "", "", "",
        "获取bkn_gtk", "置好友验证方式", "上传照片墙图片", "付款", "修改支付密码", "账号搜索", "", "", "", "取好友文件下载地址", "删除群成员_批量", "取扩列资料",
        "取资料展示设置", "设置资料展示", "获取当前登录设备信息", "提取图片文字", "取消精华", "群权限_设置加群方式", "群权限_群幸运字符", "群权限_一起写", "取QQ空间cookie",
        "修改指定QQ缓存密码", "处理群验证事件_风险号", "查询网址安全性", "", "", "禁言群匿名", "", "", "发送讨论组消息", "", "", "发送讨论组临时消息", "撤回消息_讨论组",
        "回复QQ咨询会话", "发送订阅号私聊消息", "取讨论组名称_从缓存", "修改讨论组名称", "取讨论组成员列表", "强制取自身匿名Id", "取订阅号列表", "取讨论组列表", "", "", "", "",
        "", "", "", "", "", "", "", "取讨论组文件下载地址", "", "", "取群应用列表", "退出讨论组", "群验证消息接收设置", "转让群", "修改好友备注", "删除讨论组成员",
        "", "", "拉起群收款", "结束群收款", "查询群收款状态", "支付群收款", "", "群收款_催单", "", "", "", "", "", "支付代付请求", "查询代付状态", "拉起代付",
        "取好友能量值与QID", "文字转语音", "翻译", "撤回消息_群聊s", "", "", "", "删除群成员_批量s", "拍一拍好友在线状态", "发送验证消息会话消息", "回复验证消息会话消息",
        "取群文件内存利用状态", "取群文件总数", "上传涂鸦", "上传好友文件s", "上传群文件s", "取群艾特全体剩余次数", "", "创建群相册", "删除群相册", "取群相册列表", "取群相册照片列表",
        "删除群相册照片", "修改群相册信息", "取群Id_从缓存", "上传频道图片", "发送频道消息", "发送频道私信消息", "取私信频道Id", "频道消息粘贴表情", "撤回频道消息", "撤回频道私信消息",
        "设置子频道精华消息", "禁言频道成员", "设置频道全员禁言", "移除频道成员", "移除频道成员_批量", "退出频道", "更改频道名称", "修改频道简介", "设置我的频道昵称", "置子频道观看权限",
        "置子频道发言权限", "子频道消息提醒设置", "子频道慢速模式设置", "修改子频道名称", "删除子频道", "修改我的频道用户信息_昵称", "修改我的频道用户信息_性别", "修改我的频道用户信息_年龄",
        "修改我的频道用户信息_所在地", "设置是否允许别人私信我", "设置频道加入验证方式", "搜索频道", "取频道封面", "取频道头像", "获取频道成员列表", "取频道信息", "取频道加入验证方式", "",
        "取频道文件下载地址", "", "", "", "", "取频道成员身份组", "设置频道成员身份组", "修改身份组信息", "删除身份组", "新增身份组", "取频道身份组列表", "取子频道列表",
        "取频道用户个性档案", "取频道用户资料", "刷新频道列表缓存", "取频道列表_从缓存", "取频道用户昵称_从缓存", "取频道名称_从缓存", "取子频道名称_从缓存", "取频道昵称_从缓存",
        "取私信频道列表_从缓存", "取子频道分组列表", "上传频道文件", "更改频道消息内容", "Emoji转频道EmojiId", "频道EmojiId转Emoji", "Emoji转QQ空间EmId",
        "QQ空间EmId转Emoji", "小黄豆Id转QQ空间EmId", "QQ空间EmId转小黄豆Id", "取特定身份组成员列表", "取子频道分组结构", "设置子频道分组结构", "删除子频道_批量",
        "创建子频道", "构造卡片消息文本代码", "分享音乐_频道", "修改频道排序", "处理频道加入申请", "查询群设置", "取子频道管理列表", "设置子频道管理", "设置指定身份组子频道观看权限",
        "设置指定身份组子频道发言权限", "设置直播子频道主播", "获取频道分享链接", "获取子频道分享链接", "子频道消息通知设置", "", "取话题子频道帖子列表", "获取日程列表", "获取日程链接",
        "取日程信息", "创建日程", "取QQ头像K值", "删除日程", "发送通行证到群", "发送通行证到好友", "屏蔽频道用户私信", "频道用户私信免打扰", "", "", "登录指定QQ_二次登录",
        "取框架插件列表", "", "设置频道全局公告_指定消息", "取频道号", "", "", "移动好友分组", "修改好友分组名", "删除好友分组", "取好友分组列表", "新增好友分组", "", "", "",
        "取合并转发消息内容", "上传合并转发消息", "语音转文字", "发送功能包", "", "", "", "", "", "", "", "取QQ会员中心cookie", "", "", "取最新动态列表",
        "搜索表情包", "", "经纬度定位查询详细地址", "上传群临时文件s", "删除说说", "上传QQ封面", "置消息气泡", "取收藏表情列表", "删除收藏表情", "增加收藏表情", "取个性标签列表",
        "上传个性标签图片", "取推荐消息气泡列表", "移除频道成员并撤回发言", "设置频道发言规则", "设置频道发言门槛", "设置精选展示子频道", "取表情包列表", "取表情包内表情"
    };
}

void ApplicationInfo::ProcessAppName(std::string &appName) {
    const std::string forbiddenChars = "/\\:*?\"<>|'\r\n";
    for (char c: forbiddenChars) {
        appName.erase(std::remove(appName.begin(), appName.end(), c), appName.end());
    }
}

std::string ApplicationInfo::EscapeString(const std::string &input) {
    std::string output;
    for (const char c: input) {
        switch (c) {
            case '\\': output += "\\\\";
                break;
            case '\"': output += "\\\"";
                break;
            case '\r': output += "\\r";
                break;
            case '\n': output += "\\n";
                break;
            default: output += c;
                break;
        }
    }
    return output;
}

void ApplicationInfo::SetAppName(const std::string &appName) {
    std::string processed = appName;
    ProcessAppName(processed);
    _currentAppName = processed;
}

void ApplicationInfo::AddPermissionRequest(const int permission, const std::string &reason) {
    if (permission < 1 || permission > _cnt_Apis) return;
    if (Api_names[permission - 1].empty()) return;

    const std::string escReason = EscapeString(reason);
    if (escReason.empty()) return;

    Applications << "\"" << Api_names[permission - 1] << "\":{"
            << R"("desc":")" << escReason << "\"},";
}

void ApplicationInfo::AddMultiplePermissions(const std::vector<int> &permissions,
                                                    const std::string &reason) {
    for (const int perm: permissions) {
        AddPermissionRequest(perm, reason);
    }
}

void ApplicationInfo::AddAllPermissions(const std::string &reason) {
    for (int i = 1; i <= _cnt_Apis; ++i) {
        AddPermissionRequest(i, reason);
    }
}

const char *ApplicationInfo::GetData() const {
    std::ostringstream s;
    s << "{";
    s << R"("sdkv":")" << SDK_VERSION << "\",";
    s << R"("appname":")" << _currentAppName << "\",";

    // 添加信息字段
    for (size_t i = 0; i < _infos.size(); ++i) {
        s << "\"" << _args[i] << "\":\"" << _infos[i] << "\",";
    }

    // 添加地址字段
    for (size_t i = _infos.size(); i < _args.size(); ++i) {
        s << "\"" << _args[i] << "\":" << _addres[i - _infos.size()] << ",";
    }

    // 处理权限数据
    std::string apps = Applications.str();
    if (!apps.empty() && apps.back() == ',') {
        apps.pop_back();
    }

    s << "\"data\":{"
            << "\"needapilist\":{" << apps << "}"
            << "}}";

    return s.str().data();
}