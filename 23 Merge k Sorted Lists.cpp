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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto compare = [](ListNode *&a, ListNode *&b)
        {
            return a->val > b->val;
        };

        priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> minHeap(compare);

        for (auto list : lists)
        {
            if (list)
                minHeap.push(list);
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();

            tail->next = top;
            tail = tail->next;

            if (tail->next)
                minHeap.push(tail->next);
        }

        return dummy->next;
    }
};

// class Solution
// {
// public:
//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         size_t n = lists.size();

//         return helper(lists, 0, n - 1);
//     }

// private:
//     ListNode *helper(vector<ListNode *> &lists, int l, int r)
//     {
//         if (l > r)
//             return nullptr;
//         if (l == r)
//             return lists[l];

//         int mid = l + (r - l) / 2;
//         ListNode *left = helper(lists, l, mid);
//         ListNode *right = helper(lists, mid + 1, r);

//         return mergeTwoLists(left, right);
//     }
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         if (!l1)
//             return l2;
//         if (!l2)
//             return l1;

//         if (l1->val < l2->val)
//         {
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         }
//         else
//         {
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;
//         }
//     }
// };