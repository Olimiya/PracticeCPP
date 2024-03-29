#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4};

    // 在 c++17 之前
    if (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2); itr != vec.end())
    {
        *itr = 3;
    }
    if (int a = 10; a != 10)
        return 1;
    switch (int a = 10; a)
    {
    case 1:
        /* code */
        break;
    default:
        break;
    }

    // 需要重新定义一个新的变量
    const std::vector<int>::iterator itr2 = std::find(vec.begin(), vec.end(), 3);
    if (itr2 != vec.end())
    {
        *itr2 = 4;
    }

    // 将输出 1, 4, 3, 4
    for (std::vector<int>::iterator element = vec.begin(); element != vec.end();
         ++element)
        std::cout << *element << std::endl;
}