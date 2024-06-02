#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        size_t n = s.length();
        int start = 0, maxLen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i][i] = true;
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]));
                int len = j - i + 1;
                if (dp[i][j] && maxLen < len)
                {
                    maxLen = len;
                    start = i;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         string temp = "!#";

//         for (char ch : s)
//         {
//             temp += ch;
//             temp += '#';
//         }

//         size_t n = temp.length();
//         vector<int> record(n);

//         int max = 0, c = 0, ans = 0, ansMax = 0;
//         for (int i = 1; i < n; i++)
//         {
//             record[i] = max > i ? min(record[2 * c - i], max - i) : 1;

//             while (temp[i + record[i]] == temp[i - record[i]])
//             {
//                 record[i]++;
//             };

//             if (max < i + record[i])
//             {
//                 max = i + record[i];
//                 c = i;
//             }

//             if (ansMax < record[i])
//             {
//                 ansMax = record[i];
//                 ans = i;
//             }
//         }

//         return s.substr((ans - ansMax) / 2, ansMax - 1);
//     }
// };