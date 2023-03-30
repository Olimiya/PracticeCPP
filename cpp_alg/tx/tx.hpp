#include <Map>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 递归实现格雷码
 * @param n 位数
 * @return vector<string> 格雷码
 */
vector<string> getGray(int n)
{
    vector<string> res;
    if (n == 1)
    {
        res.push_back("0");
        res.push_back("1");
        return res;
    }
    vector<string> last = getGray(n - 1);
    for (int i = 0; i < last.size(); i++)
    {
        res.push_back("0" + last[i]);
    }
    for (int i = last.size() - 1; i >= 0; i--)
    {
        res.push_back("1" + last[i]);
    }
    return res;
}

/**
 * @brief
 * @details
 * 春节期间小明使用微信收到很多个红包，非常开心。在查看领取红包记录时发现，某个红包金额出现的次数超过了红包总数的一半。
 * 请帮小明找到该红包金额。写出具体算法思路和代码实现，要求算法尽可能高效。
 * 给定一个红包的金额数组 gifts 及它的大小 n ，请返回所求红包的金额。
 * 若没有金额超过总数的一半，返回0。
 */
int getValue(vector<int> gifts, int n)
{
    if (gifts.empty() || n == 0)
        return 0;
    map<int, int> m;
    map<int, int>::iterator it;
    for (auto& e : gifts)
    {
        m[e]++;
    }
    int count = 0;
    int val = 0;
    for (it = m.begin(); it != m.end(); it++)
    {
        if (it->second > n / 2)
        {
            return it->first;
        }
    }
    return 0;
}

// 假定一种编码的编码范围是a ~
// y的25个字母，从1位到4位的编码，如果我们把该编码按字典序排序，形成一个数组如下： a, aa, aaa, aaaa,
// aaab, aaac, … …, b, ba, baa, baaa, baab, baac … …, yyyw, yyyx, yyyy
// 其中a的Index为0，aa的Index为1，aaa的Index为2，以此类推。
// 编写一个函数，输入是任意一个编码，输出这个编码对应的Index.
int get_index(string s)
{
    int len = s.length();
    int index = 0;
    for (int i = 0; i < len; i++)
    {
        index = index * 25 + s[i] - 'a';
    }
    
    return index;    
}
