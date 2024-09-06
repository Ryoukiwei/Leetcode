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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        bitset<100001> bitSet;

        for (int num : nums)
        {
            bitSet.set(num);
        }

        ListNode *dummy = new ListNode(0, head);
        ListNode *curr = dummy;

        while (curr->next)
        {
            if (bitSet[curr->next->val])
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }

        return dummy->next;
    }
};