#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ans;

        for (const char digit : num)
        {
            while (k && !ans.empty() && digit < ans.back())
            {
                ans.pop_back();
                --k;
            }

            if (digit != '0' || !ans.empty())
                ans.push_back(digit);
        }

        while (!ans.empty() && k--)
            ans.pop_back();

        return ans.empty() ? "0" : ans;
    }
};