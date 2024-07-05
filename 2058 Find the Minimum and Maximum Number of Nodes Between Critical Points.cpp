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
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        if (!head->next->next)
            return {-1, -1};

        int minDist = INT_MAX;
        int maxFront = -1, maxBack = -1;
        int idx = 1;
        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr->next)
        {
            if (curr->val > prev->val && curr->val > curr->next->val || curr->val < prev->val && curr->val < curr->next->val)
            {
                if (maxFront == -1)
                    maxFront = idx;
                if (maxBack != -1)
                    minDist = min(minDist, idx - maxBack);
                maxBack = idx;
            }

            prev = curr;
            curr = curr->next;
            ++idx;
        }

        return minDist != INT_MAX ? vector<int>{minDist, maxBack - maxFront} : vector<int>{-1, -1};
    }
};