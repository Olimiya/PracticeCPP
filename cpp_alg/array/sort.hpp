#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

/**
 * @brief sortArray
 * 排序数组
 * 912题、排序数组第一题
 * @param nums
 * @return
 */

/**
 * @brief sortArray
 * 排序数组之嘻嘻嘻
 */
vector<int> sortArray(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums;
}

/**
 * @brief sortArray_QuickSort
 * 排序数组之快速排序
 */

void quickSortPartition(vector<int> &nums, int l, int r)
{
    if (l >= r)
        return;

    int randomIndex = rand() % (r - l + 1) + l; // select a random number between l and r
    swap(nums[randomIndex], nums[r]);           // swap it with the last element
    int pivot = nums[r];                        // pivot is the last element

    int smallPtr = l - 1; // smallPtr will point to the last element smaller than pivot
    int bigPtr = r;       // bigPtr will point to the first element bigger than pivot
    int iter = l;         // iter will iterate through the array

    // [l, smallPtr] < pivot
    // [smallPtr + 1, iter - 1] == pivot
    // [bigPtr, r - 1] > pivot
    // [r] is pivot
    while (iter < bigPtr)
    {
        if (nums[iter] < pivot)
            swap(nums[++smallPtr], nums[iter++]);
        else if (nums[iter] > pivot)
            swap(nums[--bigPtr], nums[iter]);
        else
            iter++;
    }
    swap(nums[r], nums[bigPtr]); // put the pivot in the middle of the array

    quickSortPartition(nums, l, smallPtr);   // sort the left part
    quickSortPartition(nums, bigPtr + 1, r); // sort the right part
}

vector<int> sortArray_QuickSort(vector<int> &nums)
{
    // Initialize the random number generator
   srand(time(NULL));
    // Call the quicksort partition function
    quickSortPartition(nums, 0, nums.size() - 1);
    // Return the sorted vector
    return nums;
}

/**
 * @brief sortArray_MergeSort
 * 排序数组之归并排序
 * @details
Here is the explanation for the code above:
1. We pass the left and right index of the array to the function
2. We find the mid index of the array
3. We call the same function for left half and right half
4. We initialize a temporary array to store the sorted elements
5. We initialize three variables to keep track of the index of the left half, right half and
temporary array
6. We add the smallest element from either left half or right half to the temporary array
7. We repeat the above step until we reach the end of either left half or right half
8. We add the remaining elements from the other half to the temporary array
9. We copy the elements from the temporary array to the original arra
 */
void mergeSort(vector<int> &nums, int l, int r)
{
    // We will divide the array into two parts as much as possible, so we need to judge whether l >=
    // r. If l >= r, it means that the array can no longer be divided, and the current array has
    // only one element, so we return directly.
    if (l >= r)
        return;

    // We divide the array into two parts, and then sort the two parts separately.
    int mid = l + (r - l) / 2;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);

    // merge
    vector<int> temp(r - l + 1);
    int leftIter = l;
    int rightIter = mid + 1;
    int newIter = 0;

    // We merge the two sorted parts, and arrange them in order from small to large.
    while (leftIter <= mid && rightIter <= r)
    {
        if (nums[leftIter] <= nums[rightIter])
            temp[newIter++] = nums[leftIter++];
        else
            temp[newIter++] = nums[rightIter++];
    }
    while (leftIter <= mid)
        temp[newIter++] = nums[leftIter++];
    while (rightIter <= r)
        temp[newIter++] = nums[rightIter++];

    // After the merge, we need to copy the data in the temporary array to the original array.
    for (int i = 0; i < temp.size(); i++)
        nums[l + i] = temp[i];
}

vector<int> sortArray_MergeSort(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}

/**
 * @brief sortArray_HeapSort
 * 排序数组之堆排序
 * @details
 * 1. We build a max heap from the given array
 * 2. We swap the first element with the last element of the heap
 * 3. We reduce the size of the heap by 1
 * 4. We call the max heapify function on the heap
 * 5. We repeat the above steps until the size of the heap is 1
 */

void maxHeapify(vector<int> &nums, int n, int i)
{
    // index
    int maxIndex = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // left child
    if (left < n && nums[left] > nums[maxIndex])
        maxIndex = left;

    // right child
    if (right < n && nums[right] > nums[maxIndex])
        maxIndex = right;

    // exchange max
    if (maxIndex != i)
    {
        swap(nums[maxIndex], nums[i]);
        maxHeapify(nums, n, maxIndex);
    }
}

vector<int> sortArray_HeapSort(vector<int> &nums)
{
    int n = nums.size();

    // build max heap
    // counts from last non-leaf to root
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(nums, n, i);

    // sort
    for (int i = n - 1; i >= 0; i--)
    {
        // rm the max root
        swap(nums[0], nums[i]);

        // rebuild max heap
        maxHeapify(nums, i, 0);
    }
    return nums;
}

/**
 * @brief sortArray_BinSort
 * 排序数组之桶排序
 * @details
 * 1. We find the maximum and minimum element in the array
 * 2. We initialize an array of buckets
 * 3. We distribute the elements of the array into the buckets
 * 4. We sort the elements of each bucket
 * 5. We concatenate the elements of the buckets
 */
vector<int> sortArray_BinSort(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return nums;

    // find the max and min
    int maxNum = nums[0];
    int minNum = nums[0];
    for (int i = 0; i < n; i++)
    {
        maxNum = max(nums[i], maxNum);
        minNum = min(nums[i], minNum);
    }

    // initialize the bins
    int binsNum = (maxNum - minNum) / n + 1;
    vector<vector<int>> bins(binsNum);

    // arrange values to bins
    for (int i = 0; i < n; i++)
    {
        int index = (nums[i] - minNum) / n;
        bins[index].push_back(nums[i]);
    }

    // sort one bin
    for (int i = 0; i < binsNum; i++)
        sort(bins[i].begin(), bins[i].end());

    // merge all bins
    int index = 0;
    for (int i = 0; i < binsNum; i++)
        for (int j = 0; j < bins[i].size(); j++)
            nums[index++] = bins[i][j];
    return nums;
}

vector<int> sortArray_BinSort(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return nums;

    // find the max and min
    int maxNum = nums[0];
    int minNum = nums[0];
    for (int i = 1; i < n; i++)
    {
        maxNum = max(maxNum, nums[i]);
        minNum = min(minNum, nums[i]);
    }

    // init the bucket
    int bucketNum = (maxNum - minNum) / n + 1;
    vector<vector<int>> buckets(bucketNum);

    // distribute the elements into the buckets
    for (int i = 0; i < n; i++)
    {
        int index = (nums[i] - minNum) / n;
        buckets[index].push_back(nums[i]);
    }

    // sort the elements in each bucket
    for (int i = 0; i < bucketNum; i++)
        sort(buckets[i].begin(), buckets[i].end());

    // concatenate the elements in the buckets
    int index = 0;
    for (int i = 0; i < bucketNum; i++)
    {
        for (int j = 0; j < buckets[i].size(); j++)
            nums[index++] = buckets[i][j];
    }
    return nums;
}

/**
 * @brief sortArray_SelectionSort
 * 排序数组之选择排序
 * @details
 * 1. We find the minimum element in the unsorted array
 * 2. We swap the minimum element with the first element of the unsorted array
 * 3. We repeat the above steps until the array is sorted
 */
vector<int> sortArray_SelectionSort(vector<int> &nums)
{
    int n = nums.size();        // Find the size of the input vector, n
    for (int i = 0; i < n; i++) // Loop from 0 to n
    {
        int minIndex = i;               // Set the minimum index to i
        for (int j = i + 1; j < n; j++) // Loop from i + 1to n
        {
            if (nums[j]
                < nums[minIndex]) // If the current element is smaller than the minimum element
                minIndex = j;     // Set the minimum index to the current index
        }
        swap(nums[i], nums[minIndex]); // Swap the minimum element with the first element
    }
    return nums; // Return the sorted vector
}

/**
 * @brief sortArray_InsertionSort
 * 排序数组之插入排序
 * @details
 * 1. We start from the second element of the array
 * 2. We compare the current element with the previous elements
 * 3. We swap the current element with the previous element if the previous element is greater than
 * the current element
 * 4. We repeat the above steps until the array is sorted
 */
vector<int> sortArray_InsertionSort(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && nums[j] < nums[j - 1])
        {
            swap(nums[j], nums[j - 1]);
            j--;
        }
    }
    return nums;
}
