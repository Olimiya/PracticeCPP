#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

/** @brief twoSum
 * 1题、两数之和
 * @details
 * 给定一个整数数组 nums 和一个目标值 target，
 * 请你在该数组中找出和为目标值的那 两个 整数，
 * 并返回他们的数组下标。
 * @details
 * 你可以假设每种输入只会对应一个答案。
 * 但是，你不能重复利用这个数组中同样的元素。
 * @param nums
 * @param target
 * @return
 */
vector<int> twoSum_violent(vector<int>& nums, int target)
{
    vector<int> result;
    for (int i = 0; i < nums.size(); i++)
        for (int j = i + 1; j < nums.size(); j++)
            if (nums[i] + nums[j] == target)
            {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
    return result;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    // create an unordered_set with all the elements in nums
    unordered_set<int> set(nums.begin(), nums.end());
    // create a vector to store the result
    vector<int> result;
    // iterate through all the elements in nums
    for (int i = 0; i < nums.size(); i++)
    {
        // calculate the complement
        int complement = target - nums[i];
        // if the complement is in the set
        if (set.count(complement))
        {
            // find the position of the complement in the vector
            int j = find(nums.begin(), nums.end(), complement) - nums.begin();
            // if the position is the same as the current position, then continue
            if (j == i)
                continue;
            // push the current position and the complement's position into the result vector
            result.push_back(i);
            result.push_back(j);
            // return the result
            return result;
        }
    }
    // return empty vector if no solution is found
    return result;
}