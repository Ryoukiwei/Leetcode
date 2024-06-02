#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        ans.reserve(factorial(nums.size()));
        helper(nums, 0, ans);

        return ans;
    }

private:
    void helper(vector<int> &nums, int idx, vector<vector<int>> &ans)
    {
        int n = nums.size();
        if (idx == n)
        {
            ans.emplace_back(nums);
            return;
        }

        for (int i = idx; i < n; ++i)
        {
            swap(nums[idx], nums[i]);
            helper(nums, idx + 1, ans);
            swap(nums[idx], nums[i]);
        }
    }

    int factorial(int num)
    {
        int result = 1;
        for (int i = 2; i <= num; ++i)
        {
            result *= i;
        }
        return result;
    }
};

// class Solution
// {
// public:
//     vector<vector<int>> permute(vector<int> &nums)
//     {
//         int cnt = factorial(nums.size());

//         vector<vector<int>> ans;
//         ans.reserve(cnt);

//         while (cnt--)
//         {
//             ans.emplace_back(nums);
//             next_permutation(nums.begin(), nums.end());
//         }
//         return ans;
//     }

// private:
//     int factorial(int num)
//     {
//         int result = 1;
//         for (int i = 2; i <= num; ++i)
//         {
//             result *= i;
//         }
//         return result;
//     }
// };