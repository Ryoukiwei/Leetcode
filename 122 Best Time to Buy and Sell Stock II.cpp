#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        size_t n = prices.size();
        int ans = 0;

        for (int i = 0; i < n - 1; i++)
        {
            if (prices[i] < prices[i + 1])
                ans += prices[i + 1] - prices[i];
        }

        return ans;
    }
};