#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        size_t m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        auto areSame = [&](int i, int j)
        {
            return (s[i] == p[j]) || (p[j] == '.');
        };

        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] != '*')
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && areSame(i - 1, j - 1);
                else if (j > 1)
                    dp[i][j] = dp[i][j - 2] || (i > 0 && dp[i - 1][j] && areSame(i - 1, j - 2));
            }
        }

        return dp[m][n];
    }
};