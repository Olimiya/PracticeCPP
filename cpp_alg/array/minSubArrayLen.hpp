#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief minSubArrayLen
 * 长度最小的子数组
 * 209题、长度最小的子数组第一题
 * 使用暴力法
 * @param s
 * @param nums
 * @return
 */
int minSubArrayLen_violent(int s, vector<int> &nums)
{
    int minSubLen = INT_MAX;

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum >= s)
            {
                minSubLen = min(minSubLen, j - i + 1);
                break;
            }
        }
    }
    return minSubLen == INT_MAX ? 0 : minSubLen;
}

/**
 * @brief minSubArrayLen
 * 长度最小的子数组
 * 209题、长度最小的子数组第一题
 * 使用滑动窗口法
 * @param s
 * @param nums
 * @return
 */
int minSubArrayLen(int s, vector<int> &nums)
{
    int minSubLen = INT_MAX; // INT_MAX is a big number

    int n = nums.size();        // get the size of the array
    int sum = 0;                // sum of the subarray
    int i = 0;                  // start index of the subarray
    for (int j = 0; j < n; j++) // j is the end index of the subarray
    {
        sum += nums[j];  // add the new number to the subarray
        while (sum >= s) // check if the sum is big enough
        {
            minSubLen = min(minSubLen, j - i + 1); // update the subarray length
            sum -= nums[i++];                      // remove the first number of the subarray
        }
    }
    return minSubLen == INT_MAX ? 0 : minSubLen; // return the result
}

int my_lower_bound(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return nums[left] >= target ? left : -1;
}
/**
 * @brief
 * 二分法
 */
int minSubArrayLen_bisection(int s, vector<int> &nums)
{
    int n = nums.size();
    int minSubLen = n + 1;
    vector<int> sums(n + 1, 0);
    // 统计数组的前缀和
    // 其中sum[0]=0
    // sum[i]表示nums[0]到nums[i-1]的和
    for (int i = 1; i <= n; i++)
    {
        sums[i] = sums[i - 1] + nums[i - 1];
    }

    for (int i = 1; i <= n; i++) // 枚举子数组的开始位置，往后查找前缀和大于等于s + sums[i - 1]的位置
    {
        int target = s + sums[i - 1];                               // target是当前子数组的和，包括从0到i-1的和
        auto bound = lower_bound(sums.begin(), sums.end(), target); // 二分查找，找到第一个大于等于target的元素
        if (bound != sums.end())                                    // 如果找到了
        {
            int len = (int)((bound - sums.begin()) - (i - 1)); // 计算子数组的长度，由于添加了sum[i-1]，所以排除前i-1个元素
            minSubLen = min(minSubLen, len);
        }
    }
    return minSubLen == n + 1 ? 0 : minSubLen;
}