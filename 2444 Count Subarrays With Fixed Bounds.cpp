#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long ans = 0;
        auto out = nums.begin() - 1;
        auto left = nums.begin() - 1, right = nums.begin() - 1;

        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (*it < minK || *it > maxK)
                out = it;
            else
            {
                if (*it == minK)
                    left = it;
                if (*it == maxK)
                    right = it;
            }

            long long temp = min(left, right) - out;
            ans += max(0LL, temp);
        }

        return ans;
    }
};