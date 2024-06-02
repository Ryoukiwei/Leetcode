#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int ans = -1;
        helper(0, nums, k, ans);
        return ans;
    }

private:
    array<int, 1001> cnt = {};

    void helper(int i, const vector<int> &nums, const int k, int &ans)
    {
        const int n = nums.size();

        if (i >= n)
        {
            ++ans;
            return;
        }

        helper(i + 1, nums, k, ans);

        const int upper = nums[i] + k;
        const int lower = nums[i] - k;
        bool case1 = !(upper < 1001 && cnt[upper]);
        bool case2 = !(lower >= 0 && cnt[lower]);

        if (case1 && case2)
        {
            ++cnt[nums[i]];
            helper(i + 1, nums, k, ans);
            --cnt[nums[i]];
        }
    }
};