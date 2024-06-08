#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        const int n = nums.size();
        if (n < 2)
            return false;

        int sum = 0;
        unordered_map<int, int> idx{{0, -1}};

        for (int i = 0; i < n; ++i)
        {
            sum += nums[i];

            if (k)
                sum %= k;

            const auto it = idx.find(sum);
            if (it != idx.cend())
            {
                if (i - it->second >= 2)
                    return true;
            }
            else
                idx[sum] = i;
        }

        return false;
    }
};