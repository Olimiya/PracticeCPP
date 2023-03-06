#include <vector>
#include <algorithm>
#include "definition.h"
using namespace std;

/**
 * @brief removeElements
 * 移除链表元素
 * 203题、移除链表元素第一题
 * @details
 * 给你一个链表的头节点 head 和一个整数 val ，
 * 请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
 * @param head
 * @param val
 * @return
 */
ListNode *removeElements_handleHead(ListNode *head, int val)
{
    // 首先单独处理头节点，确保头节点不是要删除的节点
    while (head != nullptr && head->val == val)
    {
        auto temp = head->next;
        delete head;
        head = temp;
    }
    // 判断目前链表是否为空
    if (head == nullptr)
        return nullptr;

    auto cur = head;
    while (cur->next != nullptr) // 首先头节点确保不是要删除的节点，然后从头节点开始遍历下一个节点
    {
        if (cur->next->val == val) // 判断要删除
        {
            auto temp = cur->next->next; // 这里要临时存下来，否则删除后就找不到再下一个节点了
            delete cur->next;
            cur->next = temp;
        }
        else
            cur = cur->next;
    }
    return head;
}

/**
 * @brief removeElements
 * 使用一个虚拟节点，必定不是要找的节点。然后可以统一头节点和其他节点的处理。
 */
ListNode *removeElements(ListNode *head, int val)
{
    auto dummy = new ListNode(-1, head); // 创建一个虚拟节点，必定不是要找的节点
    auto cur = dummy;
    while (cur->next != nullptr) // 当前节点必定不是要删除的，从当前节点判定下一个节点是否要删除
    {
        if (cur->next->val == val) // 下一个节点要删除
        {
            auto temp = cur->next->next;
            delete cur->next;
            cur->next = temp;
        }
        else
            cur = cur->next; // 下一个节点不删除，移动当前节点到下一个节点
    }
    head = dummy->next;
    delete dummy;
    return head;
}