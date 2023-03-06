#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief generateMatrix
 * 螺旋矩阵 II
 * 59题、螺旋矩阵 II第一题
 * @details
 * 给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
 * @param n
 * @return
 */
vector<vector<int>> generateMatrix1(int n)
{
    vector<vector<int>> res(n, vector<int>(n));           // 初始化
    int left = 0, right = n - 1, top = 0, bottom = n - 1; // 初始化区间范围
    int num = 1;
    int tar = n * n;

    while (num <= tar) // 填入数值
    {
        for (int i = left; i <= right; i++)
        {
            res[top][i] = num++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            res[i][right] = num++;
        }
        right--;
        for (int i = right; i >= left; i--)
        {
            res[bottom][i] = num++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--)
        {
            res[i][left] = num++;
        }
        left++;
    }
    return res;
}

vector<vector<int>> generateMatrix1(int n)
{
    vector<vector<int>> res(n, vector<int>(n));           // 初始化n*n的矩阵
    int left = 0, right = n - 1, top = 0, bottom = n - 1; // 定义矩形的上下左右四个边界
    int num = 1, tar = n * n;                             // num为当前值，tar为n*n
    while (num <= tar)
    {
        for (int i = left; i <= right; i++)
        {
            res[top][i] = num++; // 从左到右填充第一行
        }
        top++; // 第一行填充完毕，上边界向下移动一位
        for (int i = top; i <= bottom; i++)
        {
            res[i][right] = num++; // 从上到下填充最右列
        }
        right--; // 最右列填充完毕，右边界向左移动一位
        for (int i = right; i >= left; i--)
        {
            res[bottom][i] = num++; // 从右到左填充最下行
        }
        bottom--; // 最下行填充完毕，下边界向上移动一位
        for (int i = bottom; i >= top; i--)
        {
            res[i][left] = num++; // 从下到上填充最左列
        }
        left++; // 最左列填充完毕，左边界向右移动一位
    }
    return res;
}