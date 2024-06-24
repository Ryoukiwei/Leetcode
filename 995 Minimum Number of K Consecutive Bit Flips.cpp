#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minKBitFlips(vector<int> &nums, int k)
    {
        const int n = nums.size();
        int ans = 0, flip = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i >= k && nums[i - k] > 1)
                --flip;

            if (flip % 2 == nums[i])
            {
                if (i + k > n)
                    return -1;

                ++ans;
                ++flip;

                nums[i] = 2;
            }
        }

        return ans;
    }
};