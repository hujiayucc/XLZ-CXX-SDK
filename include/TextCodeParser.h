//
// Created by hujiayucc on 25-5-6.
//

#ifndef TEXTCODEPARSER_H
#define TEXTCODEPARSER_H

#include "data.h"
#include <string>
#include <vector>
#include <map>

class TextCodeParser {
public:
    /**
     * @brief 解析消息内容
     * @param content 原始消息内容
     * @param[out] results 解析结果存储数组
     * @return 解析到的有效代码块数量
     * @example
     * vector<TextCodeResult> results;
     * int count = parser->Parse("[picFile,path=img.png][bq123]", results);
     */
    int Parse(const std::string& content, std::vector<TextCodeParseResult>& results) {
        // 实现解析逻辑...
        return 0;
    }

    /**
     * @brief 获取指定参数的值
     * @param codeData 代码数据（需来自解析结果）
     * @param paramName 参数名（不区分大小写）
     * @return 参数值字符串，不存在返回空字符串
     * @example GetParamValue("[picFile,path=img.png]", "PATH") → "img.png"
     */
    std::string GetParamValue(const std::string& codeData, const std::string& paramName) {
        // 实现参数提取逻辑...
        return "";
    }

    /**
     * @brief 检查参数是否存在
     * @param codeData 代码数据（需来自解析结果）
     * @param paramName 检查的参数名
     * @return 是否存在该参数
     */
    bool HasParam(const std::string& codeData, const std::string& paramName) {
        // 实现存在性检查...
        return false;
    }

    /**
     * @brief 获取所有参数列表
     * @param codeData 代码数据（需来自解析结果）
     * @param[out] params 参数存储数组
     * @return 参数数量
     */
    int GetParamList(const std::string& codeData, std::vector<TextCodeParams>& params) {
        // 实现参数列表获取...
        return 0;
    }

    /**
     * @brief 获取无参数命令的值
     * @param codeData 简单代码数据（如"[bq123]"）
     * @return 命令值（如"123"）
     */
    std::string GetCommandValue(const std::string& codeData) {
        // 实现简单命令解析...
        return codeData;
    }

    /**
     * @brief 获取原始文本代码
     * @param result 解析结果对象
     * @return 原始代码字符串
     */
    std::string GetRawCode(const TextCodeParseResult& result) {
        return result.codeData;
    }

private:
    TextCodeParser() = default;
    friend TextCodeParser* CreateTextCodeParser();
};

/**
 * @brief 创建解析器实例的工厂方法
 * @return 新创建的解析器对象指针
 * @warning 调用者需负责内存释放
 */
TextCodeParser* CreateTextCodeParser() {
    return new TextCodeParser();
}

#endif
