#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        size_t n = nums.size();
        int pos = 0, neg = 1;
        vector<int> ans(n);

        for (int num : nums)
        {
            int &i = num > 0 ? pos : neg;
            ans[i] = num;
            i += 2;
        }

        return ans;
    }
};
