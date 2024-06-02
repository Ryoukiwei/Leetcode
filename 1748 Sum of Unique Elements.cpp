#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        array<int, 101> freq = {0};
        int ans = 0;

        for (const int num : nums)
        {
            if (!freq[num])
            {
                ans += num;
                ++freq[num];
            }
            else if (freq[num] == 1)
            {
                ans -= num;
                ++freq[num];
            }
        }

        return ans;
    }
};