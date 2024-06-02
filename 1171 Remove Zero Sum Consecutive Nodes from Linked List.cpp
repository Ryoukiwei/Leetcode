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
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;

        unordered_map<int, ListNode *> record;
        int sum = 0;

        while (cur)
        {
            sum += cur->val;
            record[sum] = cur;
            cur = cur->next;
        }

        sum = 0;
        cur = dummy;

        while (cur)
        {
            sum += cur->val;
            cur->next = record[sum]->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};