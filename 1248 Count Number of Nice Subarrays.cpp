#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        return numberOfSubarraysAtMost(nums, k) - numberOfSubarraysAtMost(nums, k - 1);
    }

private:
    int numberOfSubarraysAtMost(const vector<int> &nums, int k)
    {
        int ans = 0, l = 0, r = 0;
        const int n = nums.size();

        while (!(r > n))
        {
            if (k < 0)
            {
                if (nums[l++] & 1)
                    ++k;
            }
            else
            {
                ans += r - l;
                if (r == n)
                    break;

                if (nums[r++] & 1)
                    --k;
            }
        }

        return ans;
    }
};