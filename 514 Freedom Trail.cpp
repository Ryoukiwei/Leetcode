#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int findRotateSteps(string ring, string key)
//     {
//         const int n = key.length();
//         const int m = ring.length();
//         unordered_map<char, vector<int>> posTable;

//         for (int i = 0; i < m; ++i)
//         {
//             posTable[ring[i]].emplace_back(i);
//         }

//         vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

//         for (int i = 0; i < n; ++i)
//         {
//             for (int pos : posTable[key[i]])
//             {
//                 if (!i)
//                     dp[i][pos] = min(pos, abs(m - pos));
//                 else
//                 {
//                     for (int prev : posTable[key[i - 1]])
//                     {
//                         const int diff = abs(pos - prev);
//                         const int step = min(diff, m - diff);
//                         dp[i][pos] = min(dp[i][pos], dp[i - 1][prev] + step);
//                     }
//                 }
//             }
//         }

//         int ans = INT_MAX;
//         for (int pos : posTable[key[n - 1]])
//         {
//             ans = min(ans, dp[n - 1][pos]);
//         }

//         return ans + n;
//     }
// };

class Solution
{
public:
    int findRotateSteps(string ring, string key)
    {
        n = key.length();
        m = ring.length();

        vector<vector<int>> memo(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i)
        {
            posTable[ring[i]].emplace_back(i);
        }
        return dp(ring, key, 0, 0, memo);
    }

private:
    unordered_map<char, vector<int>> posTable;
    int n, m;

    int dp(string &ring, string &key, int i, int j, vector<vector<int>> &memo)
    {
        if (j == n)
            return 0;

        if (memo[i][j])
            return memo[i][j];

        int ans = INT_MAX;

        for (int k : posTable[key[j]])
        {
            const int diff = abs(k - i);
            const int step = min(diff, m - diff);
            int remain = dp(ring, key, k, j + 1, memo);
            ans = min(ans, step + remain + 1);
        }

        return memo[i][j] = ans;
    }
};