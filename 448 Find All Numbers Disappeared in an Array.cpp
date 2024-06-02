#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> ans;
        ans.reserve(n);

        for (const int num : nums)
        {
            const int idx = abs(num) - 1;
            if (nums[idx] > 0)
                nums[idx] *= -1;
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] > 0)
                ans.emplace_back(i + 1);
        }

        return ans;
    }
};