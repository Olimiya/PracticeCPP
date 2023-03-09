#include <vector>
#include <algorithm>
#include "definition.h"
using namespace std;

/**
 * @brief getIntersectionNode
 * 相交链表
 * 160题、相交链表第一题
 * @details
 * 编写一个程序，找到两个单链表相交的起始节点。
 * @param headA
 * @param headB
 * @return
 */
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == nullptr || headB == nullptr)
        return nullptr;
    int lenA = 0;
    int lenB = 0;
    auto iter = headA;
    while (iter != nullptr)
    {
        iter = iter->next;
        lenA++;
    }
    iter = headB;
    while (iter != nullptr)
    {
        iter = iter->next;
        lenB++;
    }

    auto smallIter = headA;
    auto bigIter = headB;
    if (lenA > lenB)
    {
        smallIter = headB;
        bigIter = headA;
    }
    else
    {
        smallIter = headA;
        bigIter = headB;
    }
    int diff = abs(lenA - lenB);
    for (int i = 0; i < diff; i++)
    {
        bigIter = bigIter->next;
    }

    while (smallIter != nullptr)
    {
        if (smallIter == bigIter)
            return smallIter;
        smallIter = smallIter->next;
        bigIter = bigIter->next;
    }
    return nullptr;
}