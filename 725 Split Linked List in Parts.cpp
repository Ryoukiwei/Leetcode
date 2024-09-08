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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k);
        const int len = listLen(head);
        const int sublen = len / k;
        int r = len % k;

        ListNode *prev = nullptr, *curr = head;

        for (int i = 0; i < k; ++i, --r)
        {
            ans[i] = curr;
            for (int j = 0; j < sublen + (r > 0); ++j)
            {
                prev = curr;
                curr = curr->next;
            }

            if (prev)
                prev->next = nullptr;
        }

        return ans;
    }

private:
    int listLen(ListNode *root)
    {
        int len = 0;
        for (ListNode *curr = root; curr; curr = curr->next)
            ++len;
        return len;
    }
};