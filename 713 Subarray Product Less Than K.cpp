#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;

        int ans = 0, prod = 1;

        for (auto left = nums.begin(), right = nums.begin(); right != nums.end(); ++right)
        {
            prod *= *right;

            while (prod >= k)
                prod /= *left++;

            ans += right - left + 1;
        }

        return ans;
    }
};