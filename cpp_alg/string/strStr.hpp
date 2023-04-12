#include <iostream>
#include <string>
using namespace std;

/** @file
 * @brief 28题、实现strStr()
 * @details
 * 实现 strStr() 函数。
 * 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle
 * 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回 -1 。
 * @details
 * 说明：
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的
 * indexOf() 定义相符。
 * @details
 * 示例 1：
 * 输入：haystack = "hello", needle = "ll"
 * 输出：2
 * 示例 2：
 * 输入：haystack = "aaaaa", needle = "bba"
 * 输出：-1
 * 示例 3：
 * 输入：haystack = "", needle = ""
 * 输出：0
 * @details
 * 提示：
 * 0 <= haystack.length, needle.length <= 5 * 104
 * haystack 和 needle 仅由小写英文字符组成
 * @details
 * 方法一：暴力法
 * 方法二：KMP算法
 * @details
 * KMP算法的核心是利用已经匹配的信息，不要把“搜索位置”移回已经比较过的位置，继续把它向后移，这样就提高了效率。
 * @details
 * 举个例子，现在文本串S匹配到 i 位置，模式串P匹配到 j 位置时失配。
 * 我们已经知道：[0, i - 1] 这个位置是完全匹配的。
 * 我们已经知道：[0, j - 1] 这个位置是完全匹配的。
 * 我们已经知道：在 P[0, j - 1] 这个子串中，有一部分字符是和 [i - (j - 1), i - 1]
 * 这个位置的字符完全相同的。
 * @details
 * KMP算法。重点在于计算和理解前缀表next数组。我的理解是跳转到数组所在索引位置。计算前缀表比较难理解。
 * 时间复杂度：O(m+n)，其中 m 和 n 分别是字符串 haystack 和 needle 的长度。
 */
int strStr(string haystack, string needle)
{
    // 获取next数组
    // 计算过程使用i,j两个指针，利用动态规划的思想，将计算过程中的中间结果保存下来，避免重复计算。
    // Initialization
    int next[needle.size()]; // next数组，存储的是前缀和后缀的最长公共元素的长度
    // 示例：aabaaf，next数组为：0 1 0 1 2 2
    int j = 0;                              // j表示已经匹配的字符个数，即前缀的长度
    next[0] = 0;                            // 因为第一个字符，自己匹配自己，所以为0
    for (int i = 1; i < needle.size(); i++) // i表示当前要匹配的字符，即后缀的第一个字符
    {
        while (j > 0 && needle[i] != needle[j]) // j要保证大于0，因为下面有取j-1作为数组下标的操作
        {
            j = next[j - 1]; // 注意这里，是要找前一位的对应的回退位置了
        }
        if (needle[i] == needle[j]) // 如果当前字符匹配
        {
            j++;
        }
        next[i] = j;
    }

    // kmp
    j = 0;
    for (int i = 0; i < haystack.size(); i++)
    {
        while (j > 0 && haystack[i] != needle[j])
        {
            j = next[j - 1];
        }
        if (haystack[i] == needle[j])
            j++;
        if (j == needle.size())
            return i - j + 1;
    }
    return -1;
}
/**
 * @brief strStr_violent
 * 暴力法
 * 时间复杂度：O((n-m+1)*m)，其中 n 和 m 分别是字符串 haystack 和 needle 的长度。
 */
int strStr_violent(string haystack, string needle)
{
    for (int i = 0; i < haystack.size(); i++)
        for (int j = 0; j < needle.size(); j++)
        {
            if (haystack[i + j] != needle[j])
                break;
            if (j == needle.size() - 1)
                return i;
        }
    return -1;
}
