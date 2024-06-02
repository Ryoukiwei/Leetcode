#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        size_t n = nums.size();
        int ans = 0, sum = 0;
        unordered_map<int, int> record{{0, -1}};

        for (int i = 0; i < n; i++)
        {
            sum += (nums[i] * 2 - 1);

            if (record.find(sum) != record.end())
                ans = max(ans, i - record[sum]);
            else
                record[sum] = i;
        }

        return ans;
    }
};