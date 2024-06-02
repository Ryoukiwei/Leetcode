#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = accumulate(nums.begin(), nums.begin() + k, 0);
        int ans = sum;

        for (int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - nums[i - k];
            ans = max(ans, sum);
        }

        return static_cast<double>(ans) / k;
    }
};