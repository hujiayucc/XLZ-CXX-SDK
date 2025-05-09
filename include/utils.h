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
 * 字符串比较
 * @param s1 str1
 * @param s2 str2
 * @return 是否相等
 */
bool strequal(const char *s1, const char *s2);
#endif
