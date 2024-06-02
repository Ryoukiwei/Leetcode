#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        auto l = s.begin(), r = prev(s.end());
        while (l < r)
        {
            swap(*l++, *r--);
        }
    }
};