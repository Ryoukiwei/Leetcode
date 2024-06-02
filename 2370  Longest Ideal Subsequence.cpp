#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestIdealString(string s, int k)
    {
        array<int, 26> dp{};

        for (const char c : s)
        {
            const int i = c - 'a';
            dp[i] = 1 + longestEndsin(dp.begin(), dp.end(), i, k);
        }

        return *max_element(dp.begin(), dp.end());
    }

private:
    template <typename Iter>
    int longestEndsin(Iter first, Iter last, int i, int k)
    {
        const auto firstInRange = max(first, first + i - k);
        const auto lastInRange = min(last, first + i + k + 1);
        return *max_element(firstInRange, lastInRange);
    }
};