#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numberOfPairs(vector<int> &nums)
    {
        vector<int> freq(101, 0);

        for (const auto &num : nums)
        {
            freq[num]++;
        }

        int pairs = 0, leftoverInts = 0;

        for (int val : freq)
        {
            if (val % 2)
                leftoverInts++;

            pairs += val / 2;
        }

        return {pairs, leftoverInts};
    }
};