struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * @brief MyLinkedList
 * 707题、设计链表
 * @details
 * 请你设计一个链表，支持在链表的第一个元素前和最后一个元素后添加元素。
 * 请你完成 MyLinkedList 类：
 * MyLinkedList() 初始化 MyLinkedList 对象。
 * int get(int index) 获取链表中第 index 个节点的值。如果索引无效，返回 -1 。
 * void addAtHead(int val) 在链表的第一个元素之前添加一个值为 val 的节点。
 * 插入后，新节点将成为链表的第一个节点。
 * @details
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
class MyLinkedList
{
public:
    MyLinkedList()
    {
        head = new ListNode(-1);
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        auto cur = head;
        for (int i = 0; i <= index; i++)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val)
    {
        auto node = new ListNode(val);
        node->next = head->next;
        head->next = node;
        size++;
    }

    void addAtTail(int val)
    {
        auto node = new ListNode(val);
        auto cur = head;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = node;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        auto node = new ListNode(val);
        auto cur = head;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        node->next = cur->next;
        cur->next = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        auto cur = head;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        auto temp = cur->next->next;
        delete cur->next;
        cur->next = temp;
        size--;
    }

private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
    ListNode *head;
    int size;
};

/**
 * @brief MyLinkedList_doubly
 * 707题、设计链表
 * 双向链表
 */
class MyLinkedList_doubly
{
public:
    MyLinkedList()
    {
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        auto cur = head;
        for (int i = 0; i <= index; i++)
            cur = cur->next;
        return cur->val;
    }

    void addAtHead(int val)
    {
        auto node = new ListNode(val);
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
        node->prev = head;
        size++;
    }

    void addAtTail(int val)
    {
        auto node = new ListNode(val);
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
            return;
        auto node = new ListNode(val);
        auto cur = head;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        node->next = cur->next;
        node->prev = cur;
        cur->next->prev = node;
        cur->next = node;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        auto cur = head;
        for (int i = 0; i < index; i++)
            cur = cur->next;
        auto temp = cur->next->next;
        delete cur->next;
        cur->next = temp;
        temp->prev = cur;
        size--;
    }

private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode() : val(0), next(nullptr), prev(nullptr) {}
        ListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next), prev(nullptr) {}
    };
    ListNode *head;
    ListNode *tail;
    int size;
};
