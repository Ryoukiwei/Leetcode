#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        multiset<int> mulS;
        const int n = nums.size();
        int ans = 0, l = 0, r = 0;

        while (r < n)
        {
            mulS.insert(nums[r++]);

            while (*prev(mulS.end()) - *mulS.begin() > limit)
                mulS.erase(mulS.find(nums[l++]));

            ans = max(ans, r - l);
        }

        return ans;
    }
};