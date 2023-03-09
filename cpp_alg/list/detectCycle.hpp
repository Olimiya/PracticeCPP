#include "definition.h"
#include <algorithm>
#include <vector>
using namespace std;

/**
 * @brief detectCycle
 * 环形链表 II
 * 142题、环形链表 II第一题
 * @details
 * 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
 * @details
/* Here is the explanation for the code above:
https://leetcode.cn/problems/linked-list-cycle-ii/solution/linked-list-cycle-ii-kuai-man-zhi-zhen-shuang-zhi-/
* @param head
* @return
*/
ListNode* detectCycle(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    auto slow = head;
    auto fast = head;

    while (fast != nullptr
        && fast->next != nullptr) { // 1. if there is a cycle, fast and slow will meet some time
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) { // 2. if fast and slow meet, we move fast to the head
            fast = head;
            while (slow != fast) { // 3. we move slow and fast one step each time, they will meet at
                                   // the beginning of the cycle
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
}