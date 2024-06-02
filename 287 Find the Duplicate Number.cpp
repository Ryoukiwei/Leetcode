#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        auto slow = nums.begin(), fast = nums.begin();

        while (true)
        {
            slow = next(nums.begin(), *slow);
            fast = next(nums.begin(), *next(nums.begin(), *fast));

            if (*slow == *fast)
                break;
        }

        slow = nums.begin();
        while (*slow != *fast)
        {
            slow = next(nums.begin(), *slow);
            fast = next(nums.begin(), *fast);
        }

        return *slow;
    }
};