#include <iostream>
#include <string>
using namespace std;

/** @file
 * @brief 344题、反转字符串
 * @details
 * 双指针法，从头和尾分别出发即可。注意和链表反转区分。
 */

/** @brief reverseString
 * 344题、反转字符串
 * @details
 * 编写一个函数，其作用是将输入的字符串反转过来。
 * @details
 * 示例 1：
 * 输入：["h","e","l","l","o"]
 * 输出：["o","l","l","e","h"]
 * @details
 * 示例 2：
 * 输入：["H","a","n","n","a","h"]
 * 输出：["h","a","n","n","a","H"]
 * @param s
 */
void reverseString(vector<char>& s)
{
    // reverse the string
    int left = 0; // index of first character
    int right = s.size() - 1; // index of last character
    while (left < right)
    {
        char temp = s[left]; // store first character
        s[left] = s[right]; // exchange first character with last character
        s[right] = temp; // exchange last character with first character
        left++; // move left to next character
        right--; // move right to previous character
    }
}