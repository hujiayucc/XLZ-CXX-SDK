//
// Created by hujiayucc on 25-5-6.
//

#ifndef DATA_H
#define DATA_H

#include <vector>

// 私聊消息数据
#pragma pack(push, 1)
struct PrivateMessageData {
    int64_t senderQQ; // 发送人QQ
    int64_t frameworkQQ; // 框架QQ
    int32_t msgReq; // 消息Req
    int64_t msgSeq; // 消息Seq
    int32_t receiveTime; // 消息接收时间
    int64_t groupId; // 消息群号
    int32_t sendTime; // 消息发送时间
    int64_t msgRandom; // 消息Random
    int32_t fragmentSeq; // 消息分片序列
    int32_t fragmentCount; // 消息分片数量
    int64_t fragmentFlag; // 消息分片标识
    char* content; // 消息内容
    int32_t bubbleId; // 气泡Id
    int32_t msgType; // 消息类型
    int32_t subMsgType; // 消息子类型
    int32_t tempMsgType; // 消息子临时类型
    int32_t redPacketType; // 红包类型
    uint8_t* sessionToken; // 会话token
    int64_t sourceEventQQ; // 来源事件QQ
    char* sourceEventNick; // 来源事件QQ昵称
    char* reservedParam1; // 保留参数1
    uint8_t* reservedParam2; // 保留参数2
    char* reservedParam3; // 保留参数3
    int64_t groupMsgId; // 消息群Id
};

// 服务信息
struct ServiceInfo {
    int32_t serviceCode; // 服务代号
    int32_t serviceLevel; // 服务等级
};

// 好友信息
struct FriendInfo {
    char* email; // 邮箱
    int64_t account; // 账号
    char* nickname; // 昵称
    char* remark; // 备注
    char* onlineStatus; // 在线状态
    int32_t likesCount; // 赞数量
    char* signature; // 签名
    int32_t gender; // 性别
    int32_t qqLevel; // Q等级
    int32_t age; // 年龄
    char* country; // 国家
    char* province; // 省份
    char* city; // 城市
    std::vector<ServiceInfo> services; // 服务列表
    int32_t consecutiveOnlineDays; // 连续在线天数
    char* groupName; // 所属分组名
    int32_t todayLiked; // 今日已赞
    int32_t dailyLikeLimit; // 今日可赞数
};

// 群信息
struct GroupInfo {
    int64_t groupId; // 群ID
    int64_t groupNumber; // 群号
    int64_t reserved1; // 保留参数1
    int64_t infoQuerySeq; // 群信息查询Seq
    int64_t reserved2; // 保留参数2
    int64_t levelQuerySeq; // 群等级查询Seq
    int64_t reserved3; // 保留参数3
    int64_t muteAllUntil; // 全员禁言解除时间戳
    int64_t unmuteTime; // 解除禁言时间戳
    int64_t reserved4; // 保留参数4
    int64_t reserved5; // 保留参数5
    int64_t reserved6; // 保留参数6
    int64_t creditLevel; // 群信用等级
    int64_t reserved8; // 保留参数8
    int64_t reserved9; // 保留参数9
    int64_t reserved10; // 保留参数10
    int64_t reserved11; // 保留参数11
    int64_t memberCount; // 群成员数量
    int64_t countQuerySeq; // 群成员数量查询Seq
    int64_t cardQuerySeq; // 群成员名片查询Seq
    int64_t reserved12; // 保留参数12
    int64_t ownerQQ; // 群主QQ
    int64_t reserved13; // 保留参数13
    int64_t reserved14; // 保留参数14
    int64_t reserved15; // 保留参数15
    int64_t joinTime; // 入群时间戳
    char* groupName; // 群名称
    char* welcomeNotice; // 新人公告
};

// 讨论组成员信息
struct DiscussionMember {
    int64_t account; // 账号
    char* nickname; // 昵称
    int64_t joinTime; // 加入时间
};

// 群成员信息
struct GroupMemberInfo {
    char* account; // 账号
    int32_t age; // 年龄
    int32_t gender; // 性别
    char* nickname; // 昵称
    char* email; // 邮箱
    char* cardName; // 名片
    char* remark; // 备注
    char* title; // 头衔
    char* phone; // 手机号
    int64_t titleExpire; // 头衔到期时间
    int64_t unmuteTimestamp; // 解禁时间戳
    int64_t joinTime; // 加群时间
    int64_t lastSpeakTime; // 发言时间
    int64_t groupLevel; // 群等级
};

// 群消息数据
struct GroupMessageData {
    int64_t senderQQ; // 发送人QQ
    int64_t frameworkQQ; // 框架QQ
    int32_t msgReq; // 消息Req
    int32_t receiveTime; // 消息接收时间
    int64_t groupNumber; // 消息群号
    char* sourceGroupName; // 来源群名称
    char* senderCard; // 发送人群名片
    int32_t sendTime; // 消息发送时间
    int64_t msgRandom; // 消息Random
    int32_t fragmentSeq; // 消息分片序列
    int32_t fragmentCount; // 消息分片数量
    int64_t fragmentFlag; // 消息分片标识
    int32_t msgType; // 消息类型
    char* senderTitle; // 发送人群头衔
    char* content; // 消息内容
    char* replyContent; // 回复对象消息内容
    int32_t bubbleId; // 气泡Id
    int32_t groupLevel; // 群聊等级
    int32_t pendantId; // 挂件Id
    char* anonNickname; // 匿名昵称
    uint8_t* anonFlag; // 匿名标识
    char* reservedParam; // 保留参数
    int64_t frameworkAnonId; // 框架QQ匿名Id
    int32_t fontId; // 字体Id
};

// 群卡片信息
struct GroupCardInfo {
    char* groupName; // 群名称
    char* location; // 群地点
    char* category; // 群分类
    char* tags; // 群标签
    char* description; // 群介绍
};

// 银行卡信息
struct BankCardInfo {
    int32_t index; // 序列
    char* lastDigits; // 尾号
    char* bankName; // 银行
    char* boundPhone; // 绑定手机
    char* bindSerial; // bind_serial
    char* bankType; // bank_type
};

// QQ钱包信息
struct QQWalletInfo {
    char* balance; // 余额
    char* idNumber; // 身份证号
    char* realName; // 实名
    std::vector<BankCardInfo> bankCards; // 银行卡列表
};

// 订单详情
struct OrderDetail {
    char* orderTime; // 订单时间
    char* description; // 订单说明
    char* className; // 订单类名
    char* type; // 订单类型
    char* fee; // 订单手续费
    char* operatorQQ; // 操作人QQ
    char* operatorNick; // 操作人昵称
    char* receiverQQ; // 接收人QQ
    char* receiverNick; // 接收人昵称
    char* amount; // 操作金额
};

// 验证码信息
struct CaptchaInfo {
    char* tokenId; // token_id
    char* skey; // skey
    char* bankType; // bank_type
    char* mobile; // mobile
    char* businessType; // business_type
    int32_t random; // random
    char* transactionId; // transaction_id
    char* purchaserId; // purchaser_id
    char* token; // token
    char* authParams; // auth_params
};

// 事件消息数据
struct EventMessageData {
    int64_t frameworkQQ; // 框架QQ
    int64_t sourceGroup; // 来源群号
    int64_t operatorQQ; // 操作QQ
    int64_t triggerQQ; // 触发QQ
    int64_t msgSeq; // 消息Seq
    int32_t timestamp; // 消息时间戳
    char* sourceGroupName; // 来源群名
    char* operatorNick; // 操作QQ昵称
    char* triggerNick; // 触发QQ昵称
    char* content; // 消息内容
    int32_t msgType; // 消息类型
    int32_t subMsgType; // 消息子类型
};

// 群文件信息
struct GroupFileInfo {
    char* fileId; // fileid
    char* fileName; // filename
    int64_t fileSize; // filesize
    uint8_t* fileMd5; // filemd5
    int64_t uploaderQQ; // filefromuin
    char* uploaderNick; // filefromnick
    int32_t fileType; // filetype
};

// 频道推送数据
struct ChannelPushData {
    int64_t frameworkQQ; // 框架QQ
    int64_t frameworkUserId; // 框架频道用户Id
    int32_t msgReq; // 消息Req
    int32_t receiveTime; // 消息接收时间
    int64_t channelId; // 消息频道Id
    char* channelName; // 来源频道名称
    int64_t subChannelId; // 消息子频道Id
    char* subChannelName; // 来源子频道名称
    int64_t senderUserId; // 发送人频道用户Id
    char* senderNick; // 发送人频道昵称
    char* senderRawNick; // 发送人频道用户昵称
    int32_t eventType; // 事件类型
    int64_t dmChannelId; // 私信频道Id
    int64_t dmSubChannelId; // 私信子频道Id
    int64_t receiverUserId; // 接收人频道用户Id
    char* receiverNick; // 接收人频道昵称
    char* receiverRawNick; // 接收人频道用户昵称
    int64_t triggerUserId; // 事件触发者频道用户Id
    char* triggerNick; // 事件触发者频道昵称
    char* triggerRawNick; // 事件触发者频道用户昵称
    int32_t sendTime; // 消息发送时间
    int64_t msgRandom; // 消息Random
    int32_t originalMsgReq; // 事件原始消息Req
    int32_t subMsgReq; // 消息子Req
    int64_t triggerQQ; // 事件触发者QQ
    int32_t pushType; // 频道推送类型
    char* role; // 身份组
    char* content; // 消息内容
    char* replyContent; // 回复对象消息内容
    char* platformRoleName; // 平台身份标志名
    int32_t platformRoleId; // 平台身份标志Id
};

// 频道搜索结果
struct ChannelSearchResult {
    char* channelName; // 频道名称
    char* description; // 频道简介
    char* coverUrl; // 频道封面地址
    char* token; // 频道Token
    int64_t channelId; // 频道Id
    char* avatarUrl; // 频道头像地址
};

// 文本代码_参数列表
struct TextCodeParams {
    char* paramName; // 参数名
    bool exists; // 是否存在
    char* paramValue; // 参数值
};

// 群成员信息V2
struct GroupMemberInfoV2 {
    char* cardName; // 群名片
    char* nickname; // 昵称
    char* groupLevelText; // 群聊等级
    int64_t joinTimestamp; // 入群时间戳
    int64_t lastSpeakTimestamp; // 最后发言时间戳
    int32_t adminRole; // 管理权限
    char* title; // 头衔
};

// 资料展示设置数据
struct ProfileDisplaySettings {
    int32_t genderVisibility; // 性别
    int32_t ageVisibility; // 年龄
    int32_t birthdayVisibility; // 生日
    int32_t zodiacVisibility; // 星座
    int32_t occupationVisibility; // 职业
    int32_t companyVisibility; // 公司
    int32_t schoolVisibility; // 学校
    int32_t locationVisibility; // 所在地
    int32_t hometownVisibility; // 故乡
    int32_t emailVisibility; // 邮箱
    int32_t bioVisibility; // 个人说明
    bool showGameRecords; // 我的王者战绩
    bool showFandomBadge; // 我的粉籍
    bool showPersonalTags; // 个性标签
    bool enableAnonymousQA; // 匿问我答
    bool showLifeAchievements; // 人生成就
    bool showRecentMusic; // 最近常听
    bool showGiftsReceived; // 收到礼物
    bool showRecentGames; // 最近在玩
    bool showMusicBox; // 我的音乐盒
    bool enableStickyNotes; // 随心贴
    bool showMiniWorld; // 我的小世界
    bool showWeishi; // 我的微视
    bool showExpandProfile; // 扩列资料
};

// 订阅号信息
struct OfficialAccountInfo {
    int64_t accountId; // 订阅号Id
    char* nickname; // 昵称
    char* publicAccount; // 公众号
    char* description; // 信息简介
};

// 讨论组信息
struct DiscussionGroupInfo {
    int64_t groupId; // 讨论组Id
    int32_t memberCount; // 成员总数
    int64_t joinTimestamp; // 加入时间戳
};

// 群应用信息
struct GroupAppInfo {
    int64_t appId; // 应用Id
    char* appName; // 应用名
    char* launchUrl; // 唤醒链接
    char* iconUrl; // 应用图标
};

// GdiplusStartupInput
struct GdiplusStartupInput {
    uint32_t gdiplusVersion; // GdiplusVersion
    void *debugEventCallback; // DebugEventCallback
    bool suppressBackgroundThread; // SuppressBackgroundThread
    bool suppressExternalCodecs; // SuppressExternalCodecs
};

// 收藏表情信息
struct FavEmoticonInfo {
    char* emoticonGuid; // 表情GUID
    char* imageUrl; // 表情图片链接
};

// 个性标签信息
struct PersonalTagInfo {
    int64_t updateTime; // 更新时间
    int64_t tagId; // 标签Id
    char* content; // 标签内容
    int32_t likesCount; // 获赞数
};

// QQ推荐气泡信息
struct QQBubbleInfo {
    char* bubbleName; // 气泡名
    int64_t bubbleId; // 气泡Id
    char* imageUrl; // 气泡图片地址
};

// 表情包信息
struct EmoticonPackInfo {
    char* imageUrl; // 图片链接
    char* textCode; // 文本代码
    char* name; // 表情名
    char* md5; // 图片md5
};

// 表情包简略信息
struct EmoticonBriefInfo {
    int64_t packId; // 表情包id
    char* packName; // 表情包名称
};

// 频道成员信息
struct ChannelMemberInfo {
    char* channelNick; // 频道昵称
    char* rawNickname; // 频道用户昵称
    int64_t joinTimestamp; // 加入时间戳
    int64_t userId; // 频道用户Id
    char* platformRoleName; // 平台身份标志名
    int32_t platformRoleId; // 平台身份标志Id
    int32_t memberType; // 成员类型
};

// 频道信息
struct ChannelInfo {
    int64_t channelId; // 频道Id
    int64_t createTimestamp; // 频道创建时间戳
    int32_t memberLimit; // 频道成员数量上限
    int32_t memberCount; // 成员数量
    char* channelName; // 频道名称
    int32_t botLimit; // 频道腾讯机器人数量上限
    int32_t adminLimit; // 频道管理员数量上限
    char* description; // 频道简介
    int64_t founderId; // 创始人频道用户Id
};

// 频道用户身份组信息
struct ChannelUserRoleInfo {
    char* roleName; // 身份组名
    int64_t roleId; // 身份组Id
    int64_t colorCode; // 身份组外显颜色代码
};

// 子频道信息
struct SubChannelInfo {
    int64_t subChannelId; // 子频道Id
    char* subChannelName; // 子频道名称
    int64_t createTimestamp; // 子频道创建时间戳
    int64_t parentChannelId; // 所属频道Id
    int32_t channelType; // 子频道类型
    int32_t slowMode; // 慢速模式
    int32_t speechPermission; // 发言权限类型
    int32_t visibilityType; // 可视性类型
};

// 频道用户个性档案信息
struct ChannelUserProfile {
    int64_t profileId; // 档案Id
    char* profileName; // 档案名
    char* iconUrl; // 档案图标地址
    char* profileData; // 档案信息
};

// 频道用户信息
struct ChannelUserInfo {
    int64_t userId; // 频道用户Id
    char* nickname; // 频道用户昵称
    char* avatarUrl; // 频道用户头像地址
    char* country; // 频道用户所在国家
    char* province; // 频道用户所在省份
    char* city; // 频道用户所在市区
};

// 子频道分组信息
struct SubChannelCategory {
    char* categoryName; // 分组名
    int64_t categoryId; // 分组Id
    std::vector<long> subChannelIds; // 子频道Id列表
};

// 特定身份组成员信息
struct SpecificRoleMembers {
    char* channelNick; // 频道昵称
    char* rawNickname; // 频道用户昵称
    int64_t userId; // 频道用户Id
};

// 话题帖子子评论信息
struct TopicSubCommentInfo {
    char* commentId; // 评论Id
    int64_t commenterId; // 评论者频道用户Id
    char* commenterNick; // 评论者频道昵称
    char* commenterAvatar; // 评论者头像链接
    char* platformRoleName; // 评论者平台身份标志名
    int32_t platformRoleId; // 评论者平台身份标志Id
    std::vector<ChannelUserRoleInfo> commenterRoles; // 评论者身份组信息
    int64_t commentTime; // 评论时间戳
    char* commentToken; // 评论token
    char* content; // 评论内容
};

// 话题帖子评论信息
struct TopicCommentInfo {
    char* commentId; // 评论Id
    int64_t commenterId; // 评论者频道用户Id
    char* commenterNick; // 评论者频道昵称
    char* commenterAvatar; // 评论者头像链接
    char* platformRoleName; // 评论者平台身份标志名
    int32_t platformRoleId; // 评论者平台身份标志Id
    std::vector<ChannelUserRoleInfo> commenterRoles; // 评论者身份组信息
    int64_t commentTime; // 评论时间戳
    char* commentToken; // 评论token
    char* content; // 评论内容
    std::vector<TopicSubCommentInfo> subComments; // 子评论
};

// 话题帖子信息
struct TopicPostInfo {
    char* postId; // 帖子Id
    char* title; // 帖子标题
    int64_t authorId; // 发布人频道用户Id
    char* authorNick; // 发布人频道昵称
    char* authorAvatar; // 发布人头像链接
    char* platformRoleName; // 发布人平台身份标志名
    int32_t platformRoleId; // 发布人平台身份标志Id
    std::vector<ChannelUserRoleInfo> authorRoles; // 发布人身份组信息
    char* rawContent; // 帖子原始内容
    char* detailUrl; // 帖子详细内容链接
    char* content; // 帖子内容
    std::vector<TopicCommentInfo> comments; // 帖子评论
    char* shareCard; // 帖子分享卡片代码
    int64_t publishTime; // 帖子发布时间戳
};

// 日程信息
struct ScheduleInfo {
    int64_t creatorId; // 创建者频道用户Id
    char* creatorNick; // 创建者频道昵称
    char* creatorAvatar; // 创建者头像链接
    int64_t scheduleId; // 日程Id
    char* scheduleName; // 日程名
    char* description; // 日程描述
    int64_t startTime; // 开始时间戳
    int64_t endTime; // 结束时间戳
    int64_t createTime; // 创建时间戳
    int32_t reminderType; // 提醒
    int64_t jumpChannelId; // 开始时跳转的子频道Id
};

// 插件消息发送数据
struct PluginMessageData {
    char* pluginFileName; // 插件文件名
    char* pluginAppName; // 插件应用名
    char* apiInfo; // 插件调用API信息
    char* messageContent; // 消息内容
};

// 群成员状况简略信息
struct GroupMemberBriefStatus {
    int32_t memberLimit; // 群上限
    int32_t currentCount; // 群人数
    int64_t groupOwner; // 群主
    std::vector<long> adminList; // 管理员列表
};

// 文本代码_解析结果
struct TextCodeParseResult {
    int32_t resultType; // 结果类型
    char* command; // 命令
    char* codeData; // 文本代码数据
};

// 欲移除群成员列表
struct RemoveCandidate {
    int64_t targetQQ; // 对方QQ
    bool blockReapply; // 拒绝下次加群申请
};

// 频道身份组信息
struct ChannelRoleInfo {
    char* roleName; // 身份组名
    int64_t roleId; // 身份组Id
    int64_t displayColor; // 身份组外显颜色代码
};

// 子频道分组信息
struct SubChannelGroup {
    char* groupName; // 分组名
    int64_t groupId; // 分组Id
    std::vector<long> subChannelIds; // 子频道Id列表
};

// 特定身份组成员信息
struct RoleSpecificMember {
    char* channelNick; // 频道昵称
    char* rawNickname; // 频道用户昵称
    int64_t userId; // 频道用户Id
};

// 话题帖子子评论信息
struct TopicSubComment {
    char* commentId; // 评论Id
    int64_t commenterId; // 评论者频道用户Id
    char* commenterNick; // 评论者频道昵称
    char* commenterAvatar; // 评论者头像链接
    char* platformRole; // 平台身份标志名
    int32_t platformRoleId; // 平台身份标志Id
    std::vector<ChannelRoleInfo> commenterRoles; // 评论者身份组信息
    int64_t commentTime; // 评论时间戳
    char* commentToken; // 评论token
    char* content; // 评论内容
};

// 话题帖子评论信息
struct TopicComment {
    char* commentId; // 评论Id
    int64_t commenterId; // 评论者频道用户Id
    char* commenterNick; // 评论者频道昵称
    char* commenterAvatar; // 评论者头像链接
    char* platformRole; // 平台身份标志名
    int32_t platformRoleId; // 平台身份标志Id
    std::vector<ChannelRoleInfo> commenterRoles; // 评论者身份组信息
    int64_t commentTime; // 评论时间戳
    char* commentToken; // 评论token
    char* content; // 评论内容
    std::vector<TopicSubComment> subComments; // 子评论
};

// 插件消息发送数据
struct PluginMessage {
    char* pluginFile; // 插件文件名
    char* pluginApp; // 插件应用名
    char* apiUsage; // 插件调用API信息
    char* messageContent; // 消息内容
};

// 待付款者信息
struct PendingPayerInfo {
    int64_t QQ; // 对方QQ
    int32_t amount; // 待付款金额 (单位：分)
};

// 付款者信息
struct PaymentDetail {
    char* nickname; // 昵称
    int64_t QQ; // QQ
    int32_t dueAmount; // 应支付金额 (分)
    int32_t paymentStatus; // 支付状态
};

// 群收款信息
struct GroupCollectionInfo {
    int32_t status; // 订单状态
    int64_t initiator; // 收款发起人QQ
    int64_t sourceGroup; // 收款来源群
    char* comment; // 收款留言
    int32_t targetAmount; // 目标金额 (分)
    int32_t paidAmount; // 已支付金额 (分)
    std::vector<PaymentDetail> details; // 支付详情
};
#pragma pack(pop)
#endif
