#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        string s2 = "*" + s;
        const int n = s2.length();

        vector<int> dp(n);

        for (int i = 1; i < n; ++i)
        {
            const int l = dp[i - 1];
            if (s2[i] == ')' && s2[i - l - 1] == '(')
                dp[i] = l + dp[i - l - 2] + 2;
        }

        return *max_element(dp.begin(), dp.end());
    }
};