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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0, list1);
        ListNode *prev = dummy;

        for (int i = 0; i < a; i++)
        {
            prev = prev->next;
        }

        ListNode *temp = prev->next;
        for (int i = a; i <= b; i++)
        {
            temp = temp->next;
        }

        ListNode *tail2 = list2;
        while (tail2->next)
            tail2 = tail2->next;

        prev->next = list2;
        tail2->next = temp;

        delete dummy;

        return list1;
    }
};