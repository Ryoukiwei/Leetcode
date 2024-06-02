#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subsetXORSum(vector<int> &nums)
    {
        int ans = 0;
        for (const int num : nums)
        {
            ans |= num;
        }

        return ans << (nums.size() - 1);
    }
};