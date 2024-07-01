#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int cnt = 0;

        for (const int entry : arr)
        {
            if (entry & 1)
                ++cnt;
            else
                cnt = 0;

            if (cnt == 3)
                return true;
        }

        return false;
    }
};