#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        return sumAtMostK(nums, goal) - sumAtMostK(nums, goal - 1);
    }

private:
    int sumAtMostK(vector<int> &nums, int k)
    {
        if (k < 0)
            return 0;

        int left = 0, sum = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            sum += nums[right];

            while (sum > k)
                sum -= nums[left++];

            ans += (right - left + 1);
        }

        return ans;
    }
};