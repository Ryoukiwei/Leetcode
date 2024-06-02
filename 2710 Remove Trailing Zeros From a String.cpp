#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        auto it = prev(num.end()), begin = num.begin();
        while (it != begin)
        {
            if (*it != '0')
                break;
            --it;
            num.pop_back();
        }

        return num;
    }
};