#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        size_t m = word1.length(), n = word2.length();
        string ans;

        for (int i = 0; i < m && i < n; i++)
        {
            ans += word1[i];
            ans += word2[i];
        }

        if (m > n)
            ans += word1.substr(n);
        else
            ans += word2.substr(m);

        return ans;
    }
};