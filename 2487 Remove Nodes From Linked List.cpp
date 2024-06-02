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

// class Solution
// {
// public:
//     ListNode *removeNodes(ListNode *head)
//     {
//         if (!head)
//             return nullptr;

//         head->next = removeNodes(head->next);
//         return (head->next && head->val < head->next->val) ? head->next : head;
//     }
// };

class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        ListNode *prev = nullptr, *cur = head;

        reverse(&prev, &cur);
        cur = prev;

        while (cur)
        {
            if (cur->val < temp->val)
                cur = cur->next;
            else
            {
                temp->next = cur;
                temp = cur;
                cur = cur->next;
                temp->next = nullptr;
            }
        }

        prev = nullptr, cur = dummy->next;
        reverse(&prev, &cur);

        return prev;
    }

private:
    void reverse(ListNode **prev, ListNode **cur)
    {
        while (*cur)
        {
            swap((*cur)->next, *prev);
            swap(*prev, *cur);
        }
    }
};
