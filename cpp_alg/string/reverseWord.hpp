#include <iostream>
#include <string>
using namespace std;

string revertString(string& s, int left, int right)
{
    while (left < right)
    {
        swap(s[left++], s[right--]);
    }
    return s;
}

/** @file
 * @brief 151题、反转字符串中的单词
 * @details
 * 给定一个字符串，你需要反转字符串中每个单词的字符顺序，
 * 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
 * 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
 * 注意：输入字符串
 * s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
 * @details
 * 示例 1：
 * 输入：s = "the sky is blue"
 * 输出："blue is sky the"
 * 示例 2：
 * 输入：s = "  hello world  "
 * 输出："world hello"
 * 解释：输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 示例 3：
 * 输入：s = "a good   example"
 * 输出："example good a"
 * 解释：s 中间有多余的空格，将其减少为一个空格。
 * @details
 * 双指针法去除空格、反转字符串+反转单词。主要是方法题，要想到方法。
 */
string reverseWords(string s)
{
    // 先处理多余的空格，和普通数组的删除元素一样。
    int i = 0; // i用于记录s中已经处理的字符的个数，也是最后结果的长度
    for (int j = 0; j < s.size(); j++)
    {
        if (s[j] != ' ')
        {
            if (i != 0) // 如果不是第一个字符，则在上一个处理的单词后面添加一个空格
            {
                s[i++] = ' ';
            }
            while (j < s.size() && s[j] != ' ')
            {
                s[i++] = s[j++]; // 将s[j]复制到s[i]中，并将i和j都加1
            }
        }
    }
    s.resize(i); // resize函数用于改变vector的大小，这里截断了多余的空间
    // 翻转整个字符串
    revertString(s, 0, s.size() - 1);
    // 翻转每个单词
    int left = 0, right = 0;
    while (right < s.size())
    {
        while (right < s.size() && s[right] != ' ')
        {
            right++;
        }
        revertString(s, left, right - 1);
        left = right = right + 1;
    }
    return s;
}

/** @file
 * @brief 58题、左旋转字符串
 * @details
 * 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
 * 请定义一个函数实现字符串左旋转操作的功能。
 * 比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
 * @details
 * 示例 1：
 * 输入: s = "abcdefg", k = 2
 * 输出: "cdefgab"
 * 示例 2：
 * 输入: s = "lrloseumgh", k = 6
 * 输出: "umghlrlose"
 * @details
 * 限制：
 * 1 <= k < s.length <= 10000
 * @details
 * 不适用额外空间，原地反转
 */
string reverseLeftWords(string s, int n)
{
    // 记录一下后续反转的起始位置
    int subIndex = s.size() - n;
    // 先反转整个字符串
    revertString(s, 0, s.size() - 1);
    // 再反转前面的字符
    revertString(s, 0, subIndex - 1);
    // 最后反转后面的字符
    revertString(s, subIndex, s.size() - 1);
    return s;
}