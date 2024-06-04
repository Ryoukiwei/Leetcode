#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        array<int, 128> freq;

        for (const char c : s)
        {
            ++freq[c];
        }

        for (const int cnt : freq)
        {
            ans += cnt / 2 * 2;
        }

        ans += ans < s.length();
        return ans;
    }
};