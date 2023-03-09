#include <vector>
#include <algorithm>
#include "definition.h"
using namespace std;

/**
 * @brief removeNthFromEnd
 * 删除链表的倒数第N个节点
 * 19题、删除链表的倒数第N个节点第一题
 * @details
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 进阶：你能尝试使用一趟扫描实现吗？
 * @param head
 * @param n
 * @return
 */
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    auto dummy = new ListNode(-1, head);
    auto fast = dummy;
    auto low = dummy;

    // 1. move fast node n + 1 steps
    for (int i = 0; i < n + 1; i++)
    {
        if (fast == nullptr)
            return nullptr;
        fast = fast->next;
    }

    // 2. move fast and low node at the same time
    while (fast != nullptr)
    {
        fast = fast->next;
        low = low->next;
    }

    // 3. delete the node
    auto temp = low->next;
    low->next = temp->next;
    delete temp;

    head = dummy->next;
    delete dummy;
    return head;
}