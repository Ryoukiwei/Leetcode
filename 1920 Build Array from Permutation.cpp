#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        const int n = nums.size();

        for (int &num : nums)
        {
            num += (nums[num] % n) * n;
        }

        for (int &num : nums)
        {
            num /= n;
        }

        return nums;
    }
};