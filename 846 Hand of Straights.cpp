#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        unordered_map<int, int> cnt;
        for (const int card : hand)
        {
            ++cnt[card];
        }

        sort(hand.begin(), hand.end());

        for (const int card : hand)
        {
            const int val = cnt[card];
            if (val > 0)
            {
                const int bound = card + groupSize;
                for (int i = card; i < bound; ++i)
                {
                    if (cnt[i] < val)
                        return false;
                    cnt[i] -= val;
                }
            }
        }

        return true;
    }
};