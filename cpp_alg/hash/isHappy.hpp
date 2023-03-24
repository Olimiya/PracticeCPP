#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/** @brief isHappy
 * 202题、快乐数
 * @details
 * 编写一个算法来判断一个数是不是“快乐数”。
 * @details
 * 一个“快乐数”定义为：
 * 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
 * 然后重复这个过程直到这个数变为 1，
 * 也可能是 无限循环 但始终变不到 1。
 * 如果 可以变为  1，那么这个数就是快乐数。
 * @param n
 * @return
 */
bool isHappy(int n)
{
    int sum = 0; // sum of the square of each digit
    int sumArr[1000] = { 0 }; // array to keep track of what sums have already been calculated
    while (n != 1) // keep repeating the following steps until n is 1
    {
        while (n != 0) // keep repeating the following steps until n is 0
        {
            int temp = n % 10; // the last digit of n
            sum += temp * temp; // add the square of the last digit to sum
            n /= 10; // remove the last digit from n
        }

        // if the sum has already been calculated, then the number is not a happy number
        if (sumArr[sum] == 1)
            return false;
        else // otherwise, add the sum to the array
            sumArr[sum]++;

        n = sum; // set n to the sum
        sum = 0; // reset sum to 0
    }
    return true;
}