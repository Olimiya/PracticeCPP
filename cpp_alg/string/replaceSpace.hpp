#include <iostream>
#include <string>
using namespace std;

/**
 * @brief 5题、替换空格
 * @details
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * @details
 * 额外空间暴力解法。
 */
string replaceSpace(string s)
{
    int spaceCount = 0; // count the number of spaces in the string
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ')
            spaceCount++;
    string result; // create a new string to hold the result
    result.resize(s.size() + spaceCount * 2); // resize the string to hold the new characters
    int index = 0; // set the index to 0
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            result[index++] = '%'; // add a % character to the result string
            result[index++] = '2'; // add a 2 character to the result string
            result[index++] = '0'; // add a 0 character to the result string
        }
        else
        {
            result[index++] = s[i]; // add the character to the result string
        }
    }
    return result;
}

/** @brief 5题、替换空格
 * @details
 * 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
 * @details
 * 双指针解法。
 */
string replaceSpace_doublePointer(string s)
{
    // First, count the number of spaces in the string.
    int spaceCount = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ')
            spaceCount++;

    // Then, resize the string to account for the extra characters.
    int oldIndex = s.size() - 1;
    int newLength = s.size() + spaceCount * 2;
    s.resize(newLength);
    int newIndex = newLength - 1;

    // Finally, loop through the string backwards and replace the spaces
    // with the correct characters.
    while (newIndex >= 0)
    {
        if (s[oldIndex] != ' ')
        {
            s[newIndex] = s[oldIndex];
            newIndex--;
            oldIndex--;
        }
        else
        {
            s[newIndex--] = '0';
            s[newIndex--] = '2';
            s[newIndex--] = '%';
            oldIndex--;
        }
    }
    return s;
}