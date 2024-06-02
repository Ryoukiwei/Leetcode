#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        const int n = nums.size();

        for (int num : nums)
        {
            while (num > 0 && num <= n && num != nums[num - 1])
                swap(num, nums[num - 1]);
        }

        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            if (*it != it - nums.begin() + 1)
                return it - nums.begin() + 1;
        }

        return n + 1;
    }
};
