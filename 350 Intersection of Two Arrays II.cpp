#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        array<int, 1001> cnt;
        for (const int n1 : nums1)
        {
            ++cnt[n1];
        }

        vector<int> ans;
        for (const int n2 : nums2)
        {
            if (cnt[n2] > 0)
            {
                ans.emplace_back(n2);
                --cnt[n2];
            }
        }

        return ans;
    }
};
