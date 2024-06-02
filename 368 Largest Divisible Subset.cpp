#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        size_t n = nums.size();
        vector<int> dp(n, 1);
        vector<int> ans;

        int temp = -1, max_i = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    max_i = (max_i < dp[i]) ? dp[i] : max_i;
                }
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (max_i == dp[i] && (temp == -1 || temp % nums[i] == 0))
            {
                ans.push_back(nums[i]);
                max_i--;
                temp = nums[i];
            }
        }

        return ans;
    }
};