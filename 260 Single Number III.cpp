#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        vector<int> ans(2);
        const long xors = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
        const int low = xors & -xors;

        for (const int num : nums)
        {
            if (num & low)
                ans[0] ^= num;
            else
                ans[1] ^= num;
        }

        return ans;
    }
};