#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        size_t n = nums.size();

        sort(nums.begin(), nums.end());

        int target;
        for (int i = 0; i < n - 2; ++i)
        {
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i] == -target)
                continue;

            target = -nums[i];
            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                if ((nums[l] + nums[r]) == target)
                {
                    ans.emplace_back(vector<int>{-target, nums[l], nums[r]});
                    while (l < n - 1 && nums[l + 1] == nums[l])
                        l++;
                    while (r > 0 && nums[r - 1] == nums[r])
                        r--;

                    l++;
                    r--;
                }
                else if ((nums[l] + nums[r]) > target)
                    r--;
                else
                    l++;
            }
        }

        return ans;
    }
};