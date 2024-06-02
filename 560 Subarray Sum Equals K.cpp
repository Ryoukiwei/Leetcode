#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0, sum = 0;
        unordered_map<int, int> prefixSum = {{0, 1}};

        for (const int &num : nums)
        {
            sum += num;
            const int target = sum - k;

            if (prefixSum.count(target))
                ans += prefixSum[target];

            ++prefixSum[sum];
        }

        return ans;
    }
};