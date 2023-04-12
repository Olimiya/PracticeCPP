#include <iostream>
#include <string>
using namespace std;

/**
 * @brief repeatedSubstringPattern
 * 459题、重复的子字符串
 * @details
 * 给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。
 * 给定的字符串只含有小写英文字母，并且长度不超过10000。
 * @details
 * 示例 1:
 * 输入: "abab"
 * 输出: True
 * 解释: 可由子字符串 "ab" 重复两次构成。
 * @details
 * 示例 2:
 * 输入: "aba"
 * 输出: False
 * @details
 * 示例 3:
 * 输入: "abcabcabcabc"
 * 输出: True
 * 解释: 可由子字符串 "abc" 重复四次构成。
 * @param s
 * @return
 */
bool repeatedSubstringPattern(string s)
{
}

/** @brief repeatedSubstringPattern_violent
 * 暴力解法
 * @param s
 * @return
 */
bool repeatedSubstringPattern_violent(string s)
{
    string subStr;
    for (int i = 1; i <= s.size() / 2; i++)
    {
        subStr = s.substr(0, i);
        for (int j = i; j < s.size(); j += i)
        {
            if (s.substr(j, i) != subStr)
                break;
            if (j + i == s.size())
                return true;
        }
    }
    return false;
}