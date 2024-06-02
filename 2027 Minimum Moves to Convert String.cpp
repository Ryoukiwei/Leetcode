#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMoves(string s)
    {
        int ans = 0;
        auto it = s.begin(), send = s.end();

        while (it < send)
        {
            if (*it == 'O')
                ++it;
            else
            {
                ++ans;
                it += 3;
            }
        }

        return ans;
    }
};