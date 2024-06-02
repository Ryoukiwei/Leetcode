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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        int n = *max_element(nums.begin(), nums.end()) + 1;
        vector<bool> exist(n, false);

        for (auto num : nums)
            exist[num] = true;

        int ans = 0;
        bool flag = false;

        while (head)
        {
            if (head->val < n && exist[head->val])
            {
                if (!flag)
                {
                    flag = true;
                    ans++;
                }
            }
            else
                flag = false;

            head = head->next;
        }

        return ans;
    }
};
