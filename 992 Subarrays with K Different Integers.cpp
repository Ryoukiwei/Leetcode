#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

private:
    int atMostKDistinct(const vector<int> &nums, int k)
    {
        int ans = 0;
        vector<int> cnt(nums.size() + 1);

        for (auto left = nums.begin(), right = nums.begin(); right != nums.end(); ++right)
        {
            if (++cnt[*right] == 1)
                --k;

            while (k < 0)
            {
                if (--cnt[*left++] == 0)
                    ++k;
            }

            ans += right - left + 1;
        }

        return ans;
    }
};