#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int ans = 0;
        auto it = next(s.begin()), end = s.end();

        for (it; it != end; ++it)
        {
            ans += abs(*it - *prev(it));
        }

        return ans;
    }
};