#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortedSquares_violent(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
}

/**
 * @brief sortedSquares
 * 有序数组的平方
 * 977题、有序数组的平方第一题
 * 使用双指针法
 * @param nums
 * @return
 */
vector<int> sortedSquares(vector<int> &nums)
{
    // get the size of the array
    int n = nums.size();
    // create two index variables, one to point to the smallest number, the other to the biggest number
    int smallIndex = 0;
    int bigIndex = n - 1;
    // create a vector to store the output
    vector<int> res(n);

    // loop through the array from the last element to the first element
    for (int newIndex = n - 1; newIndex >= 0; newIndex--)
    {
        // if the absolute value of the smallest number is bigger than the absolute value of the biggest number
        if (abs(nums[smallIndex]) > abs(nums[bigIndex]))
        {
            // store the square of the smallest number in the output array
            res[newIndex] = nums[smallIndex] * nums[smallIndex];
            // move the smallest index up one
            smallIndex++;
        }
        // if the absolute value of the biggest number is bigger than the absolute value of the smallest number
        else
        {
            // store the square of the biggest number in the output array
            res[newIndex] = nums[bigIndex] * nums[bigIndex];
            // move the biggest index down one
            bigIndex--;
        }
    }
    // return the output array
    return res;
}