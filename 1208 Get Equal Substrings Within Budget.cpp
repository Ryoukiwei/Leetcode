#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        const int n = s.length();

        if (s == t)
            return n;

        int l = 0;
        for (int r = 0; r < n; ++r)
        {
            maxCost -= abs(s[r] - t[r]);
            if (maxCost < 0)
            {
                maxCost += abs(s[l] - t[l]);
                ++l;
            }
        }

        return n - l;
    }
};