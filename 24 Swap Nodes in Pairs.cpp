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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode();
        ListNode *pre = dummy;

        dummy->next = head;

        while (pre->next && pre->next->next)
        {
            ListNode *temp = pre->next->next;
            pre->next->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
            pre = temp->next;
        }

        return dummy->next;
    }
};