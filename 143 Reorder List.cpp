#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;

        ListNode *middle = findMiddle(head);
        ListNode *reversedSecond = reverseList(middle->next);
        middle->next = nullptr;

        mergeLists(head, reversedSecond);
    }

private:
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = head, *pre = nullptr;
        while (cur)
        {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }

    void mergeLists(ListNode *l1, ListNode *l2)
    {
        ListNode *t1, *t2;
        while (l1 && l2)
        {
            t1 = l1->next;
            t2 = l2->next;
            l1->next = l2;
            l2->next = t1;
            l1 = t1;
            l2 = t2;
        }
    }
};