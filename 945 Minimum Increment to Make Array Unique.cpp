#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        auto it = next(nums.begin()), end = nums.end();

        for (it; it != end; ++it)
        {
            if (!(*prev(it) < *it))
            {
                ans += *prev(it) - *it + 1;
                *it = *prev(it) + 1;
            }
        }

        return ans;
    }
};