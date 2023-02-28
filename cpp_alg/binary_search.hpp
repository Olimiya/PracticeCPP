#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief binary_search
 * 二分查找
 * 704题、二分查找第一题、数组第一题
 * @param nums
 * 输入有序数组
 * @param target
 * 查找目标
 * @return
 */
int binary_search(vector<int> &nums, int target)
{
    int left = 0;                // left border of searching interval
    int right = nums.size() - 1; // right border of searching interval

    while (left <= right)
    { // loop until we find the target or there is no elements to search
        int mid = (left + right) / 2; // find the middle of the searching interval
        // int mid = left + (right - left) / 2; // avoid overflow

        if (nums[mid] == target)     // if the middle element equals to the target
            return mid;              // we found it
        else if (nums[mid] < target) // if the middle element is less than the target
            left = mid + 1; // we can discard the left half of the searching interval (including the
                            // middle element)
        else
            right = mid - 1; // we can discard the right half of the searching interval (including
                             // the middle element)
    }
    return -1; // if we did not find the target, return -1
}

/**
 * @brief searchInsert
 * 搜索插入位置
 * 35题、二分查找第二题、数组第三题
 * @details
 * Here is the explanation for the code above:
    1. We set up two pointers, left and right, and assign them to the leftmost and rightmost index
 of the array.
    2. While left is less than or equal to right, we calculate the middle index, mid.
    3. If mid is equal to the target, we return mid.
    4. If mid is less than the target, we move the left pointer to the index after mid. (i.e. left =
 mid + 1)
    5. If mid is greater than the target, we move the right pointer to the index before mid. (i.e.
 right = mid - 1)
    6. If we cannot find the target, we return the left pointer, which is the index where the target
 should be inserted.
 * @param nums
 * 输入有序数组
 * @param target
 * 查找目标
 * @return
 */
int searchInsert(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

#pragma region 二分查找的变种：范围查找

int getLeftBorder(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target > nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int getRightBorder(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target >= nums[mid])
            left = mid + 1;
        else
            right = mid - 1;
    }

    return right;
}

int getBorder(vector<int> &nums, int target, bool isLeft = true)
{
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right)
    {
        // 1. Calculate mid
        int mid = left + (right - left) / 2;
        // 2. Check if we found the target
        bool getTarget = nums[mid] == target;
        // 3. Check if the target value is on the left side of mid
        // or on the right side of mid
        if ((getTarget && isLeft) || (target < nums[mid]))
            right = mid - 1;
        else
            left = mid + 1;
    }
    return isLeft ? left : right;
}
/**
 * @brief searchRange
 * 在排序数组中查找元素的第一个和最后一个位置
 * 34题、二分查找第三题、数组第四题
 * @details
 * Here is the explanation for the code above:
    1. getLeftBorder() returns the index of the leftmost position of target in nums, if target is
 not found, then it returns the index of the first element in nums that is greater than target.
    2. getRightBorder() returns the index of the rightmost position of target in nums, if target is
 not found, then it returns the index of the first element in nums that is smaller than target.
    3. If left is less than or equal to right, it means that the target is found in nums, and the
 range of target is [left, right], so we can push left and right into the result vector.
    4. If left is greater than right, it means that the target is not found in nums, so we can push
 -1, -1 into the result vector.
 * @param nums
 * 输入有序数组
 * @param target
 * 查找目标
 * @return
 * 返回目标的起始位置和终止位置
 */
vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> res = { -1, -1 };
    int left = getBorder(nums, target);
    int right = getBorder(nums, target, false);

    if (left <= right)
    {
        res[0] = left;
        res[1] = right;
    }
    return res;
}

/**
 * @brief searchRange_violent
 * 伪暴力法求解。
 * Here is the explanation for the code above:
    1. First we define the left and right boundaries of our search range.
    2. Then we define a vector to store the indexes of the left and right boundaries of our target
 number.
    3. We start a loop and search for the target number in the given range.
    4. If we find the target number, we store the indexes of the left and right boundaries of the
 target number in the vector.
    5. If we don't find the target number, we either search in the left half of the search range or
 the right half of the search range depending on whether the target number is smaller or larger than
 the middle element of the search range.
    6. Finally we return the vector that stores the indexes of the left and right boundaries of the
 target number.
 */
vector<int> searchRange_violent(vector<int> &nums, int target)
{
    vector<int> res = { -1, -1 };
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (target == nums[mid])
        {
            int l = mid;
            int r = mid;

            while (l >= 0 && target == nums[l])
                l--;
            while (r <= nums.size() - 1 && target == nums[r])
                r++;
            res[0] = l + 1;
            res[1] = r - 1;
            return res;
        }
        else if (target < nums[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return res;
}

#pragma endregion

/** 69. Sqrt(x) 、二分查找第四题、、数组第五题
 * @brief mySqrt
 * 求平方根
 * @details
 * Here is the explanation for the code above:
1. We use a typical binary search to find the square root.
2. We use (right - left) / 2 instead of (left + right) / 2 to avoid overflow.
3. We don't use mid * mid == x to avoid overflow.
 * @param x
 * @return
 */
int mySqrt(int x)
{
    int left = 1;
    int right = x;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (mid == x / mid)
            return mid;
        else if (mid < x / mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    // 在最后的区间是[right, left]
    // 其中left = right + 1. right * right < x, left * left > x，所以返回right。
    return right;
}

/**
 * @brief isPerferctSquare
 * 判断一个数是否是完全平方数
 * 367题、二分查找第五题、数组第六题
 * @param x
 * @return
 */
bool isPerferctSquare(int x)
{
    int left = 1;
    int right = x;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mid == x / mid && x % mid == 0) // 仅判断mid == x / mid不能保证
            return true;
        else if (mid < x / mid)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
