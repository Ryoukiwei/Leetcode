#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int checkRecord(int n)
    {
        constexpr int MOD = 1e9 + 7;
        array<long, 6> dp = {};
        dp.front() = 1;

        for (int i = 0; i < n; ++i)
        {
            const auto prev(dp);

            dp[0] = (prev[0] + prev[1] + prev[2]) % MOD;
            dp[1] = prev[0];
            dp[2] = prev[1];
            dp[3] = (prev[0] + prev[1] + prev[2] + prev[3] + prev[4] + prev[5]) % MOD;
            dp[4] = prev[3];
            dp[5] = prev[4];
        }

        long ans = 0L;
        for (const long cnt : dp)
        {
            ans = (ans + cnt) % MOD;
        }

        return ans;
    }
};