#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int ans = 0;
        size_t n = colors.length();

        for (int i = 0; i < n - 1; i++)
        {
            if (colors[i] == colors[i + 1])
            {
                ans += min(neededTime[i], neededTime[i + 1]);

                if (neededTime[i] > neededTime[i + 1])
                    swap(neededTime[i], neededTime[i + 1]);
            }
        }

        return ans;
    }
};