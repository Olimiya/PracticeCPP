#include <vector>
using namespace std;

/**
 * @brief remove_element
 * 移除元素
 * 27题、数组第二题
 * @param nums
 * @param val
 * @return
 */
int remove_element_violent(vector<int> &nums, int val)
{
    int size = nums.size(); //set a size variable to the size of the vector
    for(int i = 0; i < size; i++) //for loop to loop through the vector
    {
        if(nums[i] == val) //if the value in the vector is equal to the value we want to remove
        {
            for(int j = i + 1; j < size; j++) //loop through the vector starting after the value we want to remove
            {
                nums[j -1] = nums[j]; //set the value at j - 1 to the value at j
            }
            i--; //decrement i so we can check the value at the current index again
            size--; //decrement the size variable since we removed an element
        }
    }
    return size; //return the new size of the vector
}

/* Here is the explanation for the code above:
1. i is the index that points to the location where the elements that are not equal to val should be inserted.
2. j is the index that goes through the whole array.
3. When nums[j] != val, we should insert it into the location pointed by i, and then increment i by 1.
4. We don't need to worry about the elements after the new length because we don't care about them. */
int remove_element(vector<int> &nums, int val)
{
    int i = 0;
    for(int j = 0; j < nums.size(); j++)
    {
        if(nums[j] != val)
        {
            nums[i++] = nums[j];
        }
    }
    return i;
}
