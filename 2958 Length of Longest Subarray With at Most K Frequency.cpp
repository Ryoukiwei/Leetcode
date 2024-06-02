#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> freq;

        for (auto left = nums.begin(), right = nums.begin(); right != nums.end(); ++right)
        {
            ++freq[*right];
            while (freq[*right] > k)
                --freq[*left++];

            ans = max(ans, static_cast<int>(right - left + 1));
        }

        return ans;
    }
};