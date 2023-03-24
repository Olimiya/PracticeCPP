#include <iostream>
#include <string>
using namespace std;

/** @file
 * @brief 541题、反转字符串 II
 * @details
 * 进阶版，分成一个个小区间的简单版。注意边界值的处理。
 */

/**
 * @brief 541题、反转字符串 II
 * @details
 * 给定一个字符串和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
 * @details
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * @details
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * @details
 * 示例:
 * 输入: s = "abcdefg", k = 2
 * 输出: "bacdfeg"
 * @details
 * 要求:
 * @details
 * 该字符串只包含小写的英文字母。
 * @details
 * 给定字符串的长度和 k 在 [1, 10000] 范围内。
 */
string reverseStr(string s, int k)
{
    int index = 0;
    while (index <= s.size())
    {
        int left = index;
        int right = index + k - 1 < s.size() ? index + k - 1 : s.size() - 1;
        while (left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
        index += 2 * k;
    }
    return s;
}