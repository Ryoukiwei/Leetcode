#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int ans = 0, cur = 0;

        for (const char c : s)
        {
            if (c == '(')
                ans = max(ans, ++cur);
            else if (c == ')')
                --cur;
        }

        return ans;
    }
};