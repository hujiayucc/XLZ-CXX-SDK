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
#endif
