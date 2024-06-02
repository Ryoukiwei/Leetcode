#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        size_t n = candies.size();
        vector<bool> ans(n, false);

        for (int i = 0; i < n; i++)
        {
            candies[i] += extraCandies;
            int max = *max_element(candies.begin(), candies.end());

            if (candies[i] == max)
                ans[i] = true;

            candies[i] -= extraCandies;
        }

        return ans;
    }
};