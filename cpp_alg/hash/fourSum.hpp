#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/** @brief fourSum
 * 18题、四数之和
 * @details
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，
 * 判断 nums 中是否存在四个元素 a，b，c 和 d ，
 * 使得 a + b + c + d 的值与 target 相等？
 * 找出所有满足条件且不重复的四元组。
 * @details
 * 注意：
 * 答案中不可以包含重复的四元组。
 * @details
 * 示例：
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 满足要求的四元组集合为：
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 * @param nums
 * @param target
 * @return
 */
vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > target && nums[i] > 0)
            break;
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // 去重
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] > target && nums[j] > 0)
                break;
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue; // 去重

            int left = j + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target)
                {
                    result.push_back({ nums[i], nums[j], nums[left], nums[right] });
                    while (left < right && nums[left] == nums[left + 1])
                        left++; // 去重
                    while (left < right && nums[right] == nums[right - 1])
                        right--; // 去重
                    left++;
                    right--;
                }
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }
}