#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long ans = 0;

        sort(happiness.begin(), happiness.end(), greater<>());

        for (int i = 0; i < k; ++i)
        {
            const int cur = happiness[i] - i;
            if (cur > 0)
                ans += cur;
        }

        return ans;
    }
};