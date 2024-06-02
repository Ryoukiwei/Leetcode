#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        auto it = s.rbegin();
        while (it != s.rend() && *it == ' ')
            ++it;

        auto last = it;

        while (it != s.rend() && *it != ' ')
            ++it;

        return it - last;
    }
};