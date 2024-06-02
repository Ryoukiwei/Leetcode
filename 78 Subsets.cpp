#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        helper(nums, 0, {}, ans);

        return ans;
    }

private:
    void helper(const vector<int> &nums, int start, vector<int> &&record, vector<vector<int>> &ans)
    {
        const int n = nums.size();
        ans.emplace_back(record);

        for (int i = start; i < n; ++i)
        {
            record.emplace_back(nums[i]);
            helper(nums, i + 1, move(record), ans);
            record.pop_back();
        }
    }
};