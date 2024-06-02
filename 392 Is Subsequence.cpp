#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        size_t m = s.length(), n = t.length();

        int i = 0, j = 0;
        for (j; i < m && j < n; j++)
        {
            if (s[i] == t[j])
                i++;
        }

        return i == m;
    }
};