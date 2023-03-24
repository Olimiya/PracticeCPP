#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/** @brief fourSumCount
 * 454题、四数相加 II
 * @details
 * 给定四个包含整数的数组列表 A , B , C , D ,
 * 计算有多少个元组 (i, j, k, l) ，
 * 使得 A[i] + B[j] + C[k] + D[l] = 0。
 * 为了使问题简单化，所有的 A, B, C, D 具有相同的长度 N，
 * 且 0 ≤ N ≤ 500 。
 * 所有整数的范围在 -228 到 228 - 1 之间，
 * 最终结果不会超过 231 - 1 。
 * 例如:
 * 输入:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 * 输出:
 * 2
 * 解释:
 * 两个元组如下:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 * @param nums1
 * @param nums2
 * @param nums3
 * @param nums4
 * @return
 */
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4)
{
    // Step 1: Create a map to record the count of the sum of two elements
    //         from nums1 and nums2
    unordered_map<int, int> map;
    for (auto i : nums1)
        for (auto j : nums2)
            map[i + j]++;

    // Step 2: Initialize the count of the number of quadruplets to be zero
    int count = 0;

    // Step 3: Iterate through the elements of nums3 and nums4 to find
    //         the number of quadruplets
    for (auto i : nums3)
        for (auto j : nums4)
        {
            // Step 3.1: If the sum of two elements from nums3 and nums4
            //           is the negative of the sum of two elements from
            //           nums1 and nums2, then we have found a quadruplet.
            if (map.count(0 - i - j))
                count += map[0 - i - j];
        }
    return count;
}