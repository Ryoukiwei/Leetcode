#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;

        int cand1 = 0, cand2 = 1;
        int cnt1 = 0, cnt2 = 0;

        for (const int num : nums)
        {
            if (num == cand1)
                ++cnt1;
            else if (num == cand2)
                ++cnt2;
            else if (!cnt1)
            {
                cand1 = num;
                ++cnt1;
            }
            else if (!cnt2)
            {
                cand2 = num;
                ++cnt2;
            }
            else
            {
                --cnt1;
                --cnt2;
            }
        }

        cnt1 = cnt2 = 0;

        for (const int num : nums)
        {
            if (num == cand1)
                ++cnt1;
            else if (num == cand2)
                ++cnt2;
        }

        const int limit = nums.size() / 3;
        if (cnt1 > limit)
            ans.emplace_back(cand1);
        if (cnt2 > limit)
            ans.emplace_back(cand2);

        return ans;
    }
};