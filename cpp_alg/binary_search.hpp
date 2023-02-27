#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief binary_search
 * 二分查找
 * 704题、数组第一题
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
    {                                 // loop until we find the target or there is no elements to search
        int mid = (left + right) / 2; // find the middle of the searching interval

        if (nums[mid] == target)     // if the middle element equals to the target
            return mid;              // we found it
        else if (nums[mid] < target) // if the middle element is less than the target
            left = mid + 1;          // we can discard the left half of the searching interval (including the
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
 * 35题、数组第三题
 * @details
 * Here is the explanation for the code above:
    1. We set up two pointers, left and right, and assign them to the leftmost and rightmost index of the array.
    2. While left is less than or equal to right, we calculate the middle index, mid.
    3. If mid is equal to the target, we return mid.
    4. If mid is less than the target, we move the left pointer to the index after mid. (i.e. left = mid + 1)
    5. If mid is greater than the target, we move the right pointer to the index before mid. (i.e. right = mid - 1)
    6. If we cannot find the target, we return the left pointer, which is the index where the target should be inserted.
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