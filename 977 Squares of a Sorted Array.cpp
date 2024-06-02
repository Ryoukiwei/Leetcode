#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        size_t n = nums.size();
        int i = 0, j = n - 1;

        vector<int> ans(n);
        for (auto it = ans.rbegin(); it != ans.rend(); it++)
        {
            if (abs(nums[i]) > abs(nums[j]))
            {
                *it = nums[i] * nums[i];
                i++;
            }
            else
            {
                *it = nums[j] * nums[j];
                j--;
            }
        }

        return ans;
    }
};