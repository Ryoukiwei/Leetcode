#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.size();

        vector<int> dp(n + 1);

        for (int i = n - 1; i >= 0; --i)
        {
            dp[i] = dp[i + 1] + 1;

            for (const string &word : dictionary)
            {
                const int len = word.size();
                if (i + len <= n && memcmp(s.data() + i, word.data(), len) == 0)
                {
                    dp[i] = min(dp[i], dp[i + len]);
                }
            }
        }
        return dp[0];
    }
};