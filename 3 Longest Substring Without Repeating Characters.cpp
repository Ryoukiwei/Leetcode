#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;

        unordered_set<char> charSet;
        size_t n = s.length();
        int ans = 0, l = 0, r = 0;

        while (r < n)
        {
            if (charSet.find(s[r]) == charSet.end())
            {
                charSet.insert(s[r]);
                ans = max(ans, (r - l + 1));
                r++;
            }
            else
                charSet.erase(s[l++]);
        }

        return ans;
    }
};
