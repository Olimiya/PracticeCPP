#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/** @brief isAnagram
 * 349题、两个数组的交集
 * @details
 * 给定两个数组，编写一个函数来计算它们的交集。
 * @details
 * 示例 1:
 * 输入: nums1 = [1,2,2,1], nums2 = [2,2]
 * 输出: [2]
 * 示例 2:
 * 输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * 输出: [9,4]
 * 说明:
 * 输出结果中的每个元素一定是唯一的。
 * 我们可以不考虑输出结果的顺序。
 * @param nums1
 * @param nums2
 * @return
 */
vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    // create an empty unordered_set<int> result to store the intersection of the two arrays
    unordered_set<int> result;
    // create an unordered_set<int> set1 with the elements of nums1
    unordered_set<int> set1(nums1.begin(), nums1.end());
    // iterate through the elements of nums2
    for (auto num : nums2)
    {
        // if the current element of nums2 is in set1
        if (set1.count(num))
        {
            // insert the current element of nums2 into the result unordered_set
            result.insert(num);
        }
    }
    // return the vector<int> with the elements of result
    return vector<int>(result.begin(), result.end());
}