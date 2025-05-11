//
// Created by hujiayucc on 25-5-9.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * @brief 读取配置项
 *
 * @param filename 配置文件的路径（支持相对路径或绝对路径）
 * @param section 配置节名称（对应INI文件中[Section]格式）
 * @param key 要读取的键名
 * @param default_value 当键不存在时返回的默认值
 * @return 配置内容
 */
const char *ReadConfigItem(
    const std::string &filename,
    const std::string &section,
    const std::string &key,
    const std::string &default_value
);

/**
 * @brief 写入配置项
 *
 * @param filename 配置文件的路径（支持相对路径或绝对路径）
 * @param section 配置节名称（对应INI文件中[Section]格式）
 * @param key 要写入的键名
 * @param value 要写入的字符串值
 * @return bool
 * - true  写入成功
 * - false 写入失败
 */
bool WriteConfigItem(
    const std::string& filename,
    const std::string& section,
    const std::string& key,
    const std::string& value
);

/**
 * @brief 字符串比较
 *
 * @param s1 str1
 * @param s2 str2
 * @return 是否相等
 */
bool str_equal(const char *s1, const char *s2);

/**
 * @brief 字符串转数字
 *
 * @param num numberText
 * @return 数字
 */
int64_t str2ll(const char *num);

/**
 * @brief 字符串转数字
 *
 * @param num numberText
 * @return 数字
 */
int64_t str2ll(const std::string &num);

/**
 * @brief gbk_to_utf8
 *
 * @param gbk gbk
 * @return utf8
 */
std::string gbk2utf8(const std::string& gbk);

/**
 * @brief 文字是否包含某段文字
 *
 * @param str1 被比较的字符串
 * @param str2 被包含的字符串
 * @return 是否包含
 */
bool str_contains(const std::string& str1, const std::string& str2);

/**
 * @brief 是否以某段字符串开头
 *
 * @param str1 被比较的字符串
 * @param str2 开头字符串
 * @return 是否以某段字符串开头
 */
bool str_starts_with(const std::string& str1, const std::string& str2);

/**
 * @brief 将字符串转换为小写
 *
 * @param s 字符串
 * @return 转换后的字符串
 */
std::string toLower(const std::string& s);

/**
 * @brief 替换所有匹配的子串
 *
 * @param s 字符串
 * @param from 要替换的子串
 * @param to 替换为的子串
 * @return 替换后的字符串
 */
void replaceAll(std::string& s, const std::string& from, const std::string& to);

/**
 * @brief 取文本中右边的子串
 *
 * @param str 文本
 * @param substr 子串
 * @param start_pos 开始位置
 * @param ignore_case 是否忽略大小写
 * @param forward_search 是否正向搜索
 * @return
 */
std::string text_get_right(
    const std::string& str,
    const std::string& substr,
    int start_pos = -1,
    bool ignore_case = false,
    bool forward_search = false
);

/**
 * @brief 替换子串标记
 *
 * @param s 源字符串
 */
void replaceSubstrMark(std::string& s);

/**
 * @brief 安全的起始位置
 *
 * @param start_pos 起始位置
 * @param str_len 字符串长度
 * @param forward 是否正向搜索
 * @return 安全的起始位置
 */
size_t safeStartPos(int start_pos, size_t str_len, bool forward);

/**
 * @brief 取文本中左边的子串
 *
 * @param str 源字符串
 * @param substr 子串
 * @param start_pos 起始位置
 * @param ignore_case 是否忽略大小写
 * @param forward_search 是否正向搜索
 * @return 获取的子串
 */
std::string text_get_left(
    const std::string& str,
    const std::string& substr,
    int start_pos = -1,
    bool ignore_case = false,
    bool forward_search = true
);
#endif
