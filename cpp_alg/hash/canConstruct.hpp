#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/** @brief canConstruct
 * 383题、赎金信
 * @details
 * 给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，
 * 判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
 * 如果可以构成，返回 true ；否则返回 false。
 * @details
 * (注意：
 * 你可以假设两个字符串均只含有小写字母。)
 * @details
 * canConstruct("a", "b") -> false
 * canConstruct("aa", "ab") -> false
 * canConstruct("aa", "aab") -> true
 * @param ransomNote
 * @param magazine
 * @return
 */
bool canConstruct(string ransomNote, string magazine)
{
    vector<int> count(26, 0);

    for (int i = 0; i < magazine.size(); i++)
    {
        count[magazine[i] - 'a']++;
    }

    for (int i = 0; i < ransomNote.size(); i++)
    {
        count[ransomNote[i] - 'a']--;
        if (count[ransomNote[i] - 'a'] < 0)
            return false;
    }
    return true;
}