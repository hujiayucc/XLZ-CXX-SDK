//
// Created by hujiayucc on 25-5-6.
//

#ifndef TEXTCODE_H
#define TEXTCODE_H

#include <string>
#include <sstream>
#include <windows.h>

class TextCode {
public:
    /**
     * @brief 生成本地音频消息代码
     * @param filePath 音频文件路径（必须为silk_v3或amr格式）
     * @param voiceType 语音类型（0=普通，1=变声，2=文字，3=红包匹配）
     * @param textContent 语音附加文字内容（最大支持300字符）
     * @param duration 音频时长（单位：毫秒，范围100-60000）
     * @return 音频消息代码，格式：[AudioFile,path=xxx,type=N,...]
     * @warning 文件路径需包含完整扩展名，否则可能无法识别
     */
    static std::string audioLocal(const std::string& filePath, int voiceType, const std::string& textContent , int duration);

    /**
     * @brief 生成小黄豆表情代码
     * @param id 表情编号（范围1-200）
     * @return 表情代码，格式：[bqN]
     * @example 小黄豆表情(204) → [bq204]
     */
    static std::string smallBeanEmoji(int id);

    /**
     * @brief 生成大表情代码
     * @param emojiId 表情唯一标识（需从消息日志获取）
     * @param emojiName 表情显示名称
     * @param hashValue 表情哈希值（32位MD5）
     * @param flagValue 表情标识符（16位hex）
     * @return 大表情代码，格式：[bigFace,Id=xxx,...]
     * @note hash和flag参数需严格对应有效表情数据
     */
    static std::string largeEmoji(int emojiId, const std::string& emojiName, const std::string& hashValue, const std::string& flagValue);

    /**
     * @brief 生成小表情代码
     * @param faceId 表情系统ID
     * @param faceName 表情显示名称
     * @return 小表情代码，格式：[smallFace,name=xxx,Id=N]
     * @note 名称需与官方定义一致（区分大小写）
     */
    static std::string smallFaceEmoji(int faceId, const std::string& faceName);

    /**
     * @brief 生成标准表情代码
     * @param faceId 表情编号（参考QQ表情ID表）
     * @param faceName 表情名称（如[微笑]）
     * @return 标准表情代码，格式：[Face,Id=N,name=xxx]
     * @example 标准表情(14, "微笑") → [Face,Id=14,name=微笑]
     */
    static std::string standardEmoji(int faceId, const std::string& faceName);

    /**
     * @brief 生成@用户代码
     * @param targetId 目标用户QQ号（群内有效）
     * @param addSpace 是否添加尾部空格（美化显示）
     * @return @代码，格式：[@123456] 或 [@123456] 
     * @warning 非群聊场景下可能显示异常
     */
    static std::string atUser(long long targetId, bool addSpace);

    /**
     * @brief 生成@全体成员代码
     * @return @全体代码，固定格式：[@all]
     * @note 需要管理员权限才能生效
     */
    static std::string atAll();

    /**
     * @brief 生成本地图片代码
     * @param filePath 图片文件路径
     * @param width 图片宽度（单位：像素）
     * @param height 图片高度（单位：像素）
     * @param isAnimated 是否为动态图片
     * @param previewText 预览文字（最多20字符）
     * @return 图片代码，格式：[picFile,path=xxx,...]
     * @warning 动态图片需为GIF格式
     */
    static std::string imageLocal(const std::string& filePath, int width, int height, bool isAnimated, const std::string& previewText);

    /**
     * @brief 生成回复消息代码
     * @param originalContent 被回复消息内容
     * @param senderId 原消息发送者QQ号
     * @param timestamp 原消息时间戳（10位Unix时间）
     * @param requestId 消息请求ID
     * @param randomSeed 消息随机种子
     * @return 回复消息代码，格式：[Reply,Content=xxx,...]
     * @note 原消息内容会自动进行USC2编码转换
     */
    static std::string replyMessage(const std::string& originalContent, long long senderId, int timestamp, int requestId, long long randomSeed);

private:
    /**
     * @brief UTF-8转UTF-16LE编码（Windows实现）
     * @param utf8 UTF-8编码字符串
     * @return UTF-16LE字节序列
     * @warning 返回结果包含空字符，需用二进制方式处理
     */
    static std::string utf8ToUsc2(const std::string& utf8);

    /**
     * @brief UTF-16LE转UTF-8编码（Windows实现）
     * @param usc2 UTF-16LE字节序列
     * @return UTF-8编码字符串
     * @note 输入必须为有效UTF-16LE数据
     */
    static std::string usc2ToUtf8(const std::string& usc2);
};
#endif