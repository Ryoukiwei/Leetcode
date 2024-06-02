#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int ans = 0;
        auto tkbegin = tickets.begin(), tkend = tickets.end();
        auto target = tkbegin + k;

        for (auto it = tkbegin; it != tkend; ++it)
        {
            ans += min(*it, *target - (it > target));
        }

        return ans;
    }
};
