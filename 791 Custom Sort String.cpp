#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        string ans = "";
        vector<int> freq(26, 0);

        for (char c : s)
        {
            freq[c - 'a']++;
        }

        for (char c : order)
        {
            while (freq[c - 'a']-- > 0)
                ans += c;
        }

        for (char c : s)
        {
            while (freq[c - 'a']-- > 0)
                ans += c;
        }

        return ans;
    }
};
