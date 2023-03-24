#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

/** @brief threeSum
 * 15题、三数之和
 * @details
 * 给你一个包含 n 个整数的数组 nums，
 * 判断 nums 中是否存在三个元素 a，b，c ，
 * 使得 a + b + c = 0 ？
 * 请你找出所有和为 0 且不重复的三元组。
 * @details
 * 注意：答案中不可以包含重复的三元组。
 * @details
 * 示例 1：
 * 输入：nums = [-1,0,1,2,-1,-4]
 * 输出：[[-1,-1,2],[-1,0,1]]
 * 示例 2：
 * 输入：nums = []
 * 输出：[]
 * 示例 3：
 * 输入：nums = [0]
 * 输出：[]
 * @details
 * 哈希法
 * @param nums
 * @return
 */
vector<vector<int>> threeSum_hash(vector<int>& nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    // 哈希法
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // 去重
        unordered_set<int> set;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (set.count(-nums[i] - nums[j]))
            {
                result.push_back({ nums[i], nums[j], -nums[i] - nums[j] });
                while (j + 1 < nums.size() && nums[j] == nums[j + 1])
                    j++; // 去重
            }
            set.insert(nums[j]);
        }
    }
    return result;
}

/**
 * @brief threeSum
 * 15题、三数之和
 * @details
 * 双指针法
 * @details
 * 1. 先对数组进行排序
 * 2. 遍历数组，对于每个元素，使用双指针在它后面的数组中寻找两个数，使得它们的和为 -nums[i]
 * 3. 为了避免重复解，需要跳过重复的元素
 */
vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    // sort the array first
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++)
    {
        // If the current number is greater than 0, then the sum of three numbers is greater than 0,
        // so the loop is ended.
        if (nums[i] > 0)
            break;
        // Skip duplicate numbers
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        // left pointer
        int left = i + 1;
        // right pointer
        int right = nums.size() - 1;
        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0)
            {
                result.push_back({ nums[i], nums[left], nums[right] });
                // Skip duplicate numbers
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                // Skip duplicate numbers
                while (left < right && nums[right] == nums[right - 1])
                    right--;
                left++;
                right--;
            }
            else if (sum > 0)
                right--;
            else
                left++;
        }
    }
    return result;
}