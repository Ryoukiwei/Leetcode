#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &score)
    {
        const int n = score.size();
        vector<string> ans(n);
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(),
             [&](const int a, const int b)
             {
                 return score[a] > score[b];
             });

        for (int i = 0; i < n; ++i)
        {
            if (i == 0)
                ans[idx[i]] = "Gold Medal";
            else if (i == 1)
                ans[idx[i]] = "Silver Medal";
            else if (i == 2)
                ans[idx[i]] = "Bronze Medal";
            else
                ans[idx[i]] = to_string(i + 1);
        }

        return ans;
    }
};