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

// Not fast enough
//
// class Solution
// {
// public:
//     bool isPalindrome(ListNode *head)
//     {
//         ListNode *temp = head;
//         return helper(head, temp);
//     }

// private:
//     bool helper(ListNode *node, ListNode *&cur)
//     {
//         if (!node)
//             return true;

//         bool ans = helper(node->next, cur) && (cur->val == node->val);
//         cur = cur->next;

//         return ans;
//     }
// };

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {

        if (!head || !head->next)
            return true;

        ListNode *mid = head, *start = head;

        while (start && start->next)
        {
            mid = mid->next;
            start = start->next->next;
        }

        ListNode *end = nullptr, *temp = nullptr;

        while (mid)
        {
            temp = mid->next;
            mid->next = end;
            end = mid;
            mid = temp;
        }

        start = head;

        while (start && end)
        {
            if (start->val != end->val)
                return false;

            start = start->next;
            end = end->next;
        }

        return true;
    }
};