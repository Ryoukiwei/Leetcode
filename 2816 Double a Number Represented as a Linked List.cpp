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
    ListNode *doubleIt(ListNode *head)
    {
        if (head->val > 4)
            head = new ListNode(0, head);

        ListNode *cur = head;
        while (cur)
        {
            if (cur->val > 4)
                cur->val -= 5;
            cur->val *= 2;

            if (cur->next && cur->next->val > 4)
                ++cur->val;

            cur = cur->next;
        }

        return head;
    }
};

// class Solution
// {
// public:
//     ListNode *doubleIt(ListNode *head)
//     {
//         ListNode *prev = nullptr, *cur = head;
//         reverse(&prev, &cur);
//         head = prev;

//         bool carry = false;
//         ListNode *node = head;
//         while (node)
//         {
//             node->val *= 2;
//             if (carry)
//                 ++node->val;
//             carry = node->val > 9 ? true : false;
//             node->val %= 10;

//             if (!node->next && carry)
//             {
//                 node->next = new ListNode(1);
//                 break;
//             }

//             node = node->next;
//         }

//         prev = nullptr;
//         cur = head;
//         reverse(&prev, &cur);
//         return prev;
//     }

// private:
//     void reverse(ListNode **prev, ListNode **cur)
//     {
//         while (*cur)
//         {
//             swap((*cur)->next, *prev);
//             swap(*prev, *cur);
//         }
//     }
// };
