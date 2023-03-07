#include <vector>
#include <algorithm>
#include "definition.h"
using namespace std;

/**
 * @brief swapPairs
 * 两两交换链表中的节点
 * 24题、两两交换链表中的节点第一题
 * @details
 * 给你一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * @param head
 * @return
 */
ListNode *swapPairs(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    auto dummy = new ListNode(-1, head);
    auto pre = dummy;
    auto cur = head;
    while (cur != nullptr && cur->next != nullptr)
    {
        // step 1: isolate the next node from the rest of the list
        auto next = cur->next;
        auto temp = next->next;

        // step 2: swap the next node with the previous node
        pre->next = next;
        next->next = cur;
        cur->next = temp;

        // step 3: move to the next pair of nodes
        pre = cur;
        cur = temp;
    }
    head = dummy->next;
    delete dummy;
    return head;
}