#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/** @brief isAnagram
 * 242题、有效的字母异位词
 * @details
 * 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
 * @details
 * 示例 1:
 * 输入: s = "anagram", t = "nagaram"
 * 输出: true
 * 示例 2:
 * 输入: s = "rat", t = "car"
 * 输出: false
 * 说明:
 * 你可以假设字符串只包含小写字母。
 * @param s
 * @param t
 * @return
 */
bool isAnagram(string s, string t)
{
    if (s.size() != t.size())
        return false;
    // if two strings have different length, return false
    vector<int> count(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        count[s[i] - 'a']++;
        count[t[i] - 'a']--;
    }
    // count the number of each character in string s and t
    // and subtract the number of each character in string t from the number in string s
    // so that the number of each character in string s and t are the same
    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
            return false;
    }
    // if any character in string s and t are different, return false
    return true;
}