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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre = dummy, *cur = head;

        int n = 0;

        while (cur)
        {
            cur = cur->next;
            n++;
        }

        while (n >= k)
        {
            cur = pre->next;
            for (int i = 1; i < k; i++)
            {
                ListNode *temp = cur->next;
                cur->next = temp->next;
                temp->next = pre->next;
                pre->next = temp;
            }

            pre = cur;
            n -= k;
        }

        return dummy->next;
    }
};