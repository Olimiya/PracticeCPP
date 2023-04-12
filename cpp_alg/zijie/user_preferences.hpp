#include <iostream>
#include <vector>
using std::vector;

// 第1行为n代表用户的个数
// 第2行为n个整数，第i个代表用户标号为i的用户对某类文章的喜好度
// 第3行为一个正整数q代表查询的组数
// 第4行到第（3+q）行，每行包含3个整数l,r,k代表一组查询，即标号为l<=i<=r的用户中对这类文章喜好值为k的用户的个数。
/* 数据范围n <= 300000,q<=300000 k是整型 */

// 输出q行，每行一个整数代表喜好值为k的用户的个数
// 输入：
// 5
// 1 2 3 3 5
// 3
// 1 2 1
// 2 4 5
// 3 5 3
// 输出：
// 1
// 0
// 2

/// @brief
/// @return
int main()
{
    // 处理输入
    int n;
    std::cin >> n; // user count
    std::vector<int> user_preferences(n);
    for (int i = 0; i < n; i++)
        std::cin >> user_preferences[i];
    int query_count;
    std::cin >> query_count;
    std::vector<std::vector<int>> queries(query_count, std::vector<int>(3));
    for(int i = 0; i < query_count; i++)
        for(int j = 0; j < 3; j++)
            std::cin >> queries[i][j];

    // 计算
    // 方法1：直接遍历
    // 分析：如果q很大，那么这种方法的时间复杂度是O(nq)，会超时
    vector<int> result;
    for(int i= 0; i < query_count; i++)
    {
        int count = 0;
        for(int j = queries[i][0] - 1; j < queries[i][1]; j++)
        {
            if(user_preferences[j] == queries[i][2])
                count++;
        }
        result.push_back(count);
    }
    for(int i = 0; i < result.size(); i++)
        std::cout << result[i] << std::endl;


    // 方法2：基数排序+累计和
    // 分析：用空间换时间，减小每次q的时间复杂度，时间复杂度为O(n+q)
    // 1. 基数排序
    vector<vector<int>> buckets(vector<int>(n));

    int max = user_preferences[0];
    for(int i = 1; i < n; i++)
    {
        if(user_preferences[i] > max)
            max = user_preferences[i];
    }
    int max_digit = 0;
    while(max)
    {
        max /= 10;
        max_digit++;
    }
    int radix = 1;
    
}