#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        long long ans = 0;
        int prefix = 0;
        array<int, 1024> cnt{};
        cnt[0] = 1;

        for (const char c : word)
        {
            prefix ^= 1 << (c - 'a');
            ans += cnt[prefix];

            for (int i = 0; i < 10; ++i)
            {
                ans += cnt[prefix ^ 1 << i];
            }

            ++cnt[prefix];
        }

        return ans;
    }
};