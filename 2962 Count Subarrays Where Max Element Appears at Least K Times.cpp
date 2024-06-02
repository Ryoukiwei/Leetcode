#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        const int MAX = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int freq = 0;

        for (auto left = nums.begin(), right = nums.begin(); right != nums.end(); ++right)
        {
            if (*right == MAX)
                ++freq;

            while (freq == k)
            {
                if (*left++ == MAX)
                    --freq;
            }

            ans += left - nums.begin();
        }

        return ans;
    }
};