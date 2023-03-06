#include <vector>
using namespace std;

/**
 * @brief remove_element
 * 移除元素
 * 27题、移除元素第一题
 * 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val
 * 的元素，并返回移除后数组的新长度。
 * @param nums
 * @param val
 * @return
 */
int remove_element_violent(vector<int> &nums, int val)
{
    int size = nums.size();        // set a size variable to the size of the vector
    for (int i = 0; i < size; i++) // for loop to loop through the vector
    {
        if (nums[i] == val) // if the value in the vector is equal to the value we want to remove
        {
            for (int j = i + 1; j < size;
                 j++) // loop through the vector starting after the value we want to remove
            {
                nums[j - 1] = nums[j]; // set the value at j - 1 to the value at j
            }
            i--;    // decrement i so we can check the value at the current index again
            size--; // decrement the size variable since we removed an element
        }
    }
    return size; // return the new size of the vector
}

/* Here is the explanation for the code above:
1. i is the index that points to the location where the elements that are not equal to val should be
inserted.
2. j is the index that goes through the whole array.
3. When nums[j] != val, we should insert it into the location pointed by i, and then increment i
by 1.
4. We don't need to worry about the elements after the new length because we don't care about them.
*/
int remove_element(vector<int> &nums, int val)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != val)
        {
            nums[i++] = nums[j];
        }
    }
    return i;
}

/**
 * @brief removeDuplicates
 * 删除排序数组中的重复项
 * 26题、移除元素第二题
 * @param nums
 * @return
 */
int removeDuplicates(vector<int> &nums)
{
    int i = 0; // i is the index of the last distinct number
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[j] != nums[i])
        {
            nums[++i] = nums[j];
        }
    }
    return i + 1;
}

/**
 * @brief moveZeroes
 * 移动零
 * 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
 * 283题、移除元素第三题
 * @param nums
 * @return
 */
void moveZeroes(vector<int> &nums)
{
    // 1. Move all non-zero numbers to the left side of the array
    int i = 0; // i is the index of the last non-zero number
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
            nums[i++] = nums[j];
    }
    // 2. Fill the rest of the array with 0s
    for (int j = i; j < nums.size(); j++)
        nums[j] = 0;
}
