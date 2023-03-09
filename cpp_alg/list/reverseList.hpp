#include <vector>
#include <algorithm>
#include "definition.h"
using namespace std;

/**
 * @brief reverseList
 * 反转链表
 * 206题、反转链表第一题
 * @details
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * @param head
 * @return
 */
ListNode *reverseList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    auto pre = head;
    auto next = head->next;
    while (next != nullptr)
    {
        // 1. save the next->next node
        auto temp = next->next;
        // 2. reverse the next node
        next->next = pre;
        // 3. move pre and next node
        pre = next;
        next = temp;
    }
    // 4. make sure the head node's next is null
    head->next = nullptr;
    return pre;
}