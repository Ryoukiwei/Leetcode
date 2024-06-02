#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        size_t n = s.length();
        int ans = 0, count = 0;

        for (int i = 0, j = 0; i < n; ++i)
        {
            if (i && s[i] == s[i - 1])
                count++;

            while (count > 1)
            {
                if (s[j] == s[j + 1])
                    count--;
                j++;
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};