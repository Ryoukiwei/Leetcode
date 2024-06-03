#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int appendCharacters(string s, string t)
    {
        auto it = t.begin(), end = t.end();

        for (const char c : s)
        {
            if (c != *it)
                continue;

            if (++it == end)
                return 0;
        }

        return end - it;
    }
};