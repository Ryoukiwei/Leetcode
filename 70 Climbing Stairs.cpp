#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // int climbStairs(int n)
    // {
    //     if (n == 1)
    //         return 1;

    //     vector<int> dp(n + 1);
    //     dp[0] = 1;
    //     dp[1] = 1;

    //     for (int i = 2; i <= n; i++)
    //     {
    //         dp[i] = dp[i - 1] + dp[i - 2];
    //     }

    //     return dp[n];
    // }

    int climbStairs(int n)
    {
        double sqrt5 = sqrt(5);
        double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
        return round(fibn / sqrt5);
    }
};