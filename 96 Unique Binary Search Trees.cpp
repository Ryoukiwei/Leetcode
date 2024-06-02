#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        return binom(2 * n, n) / (n + 1);
    }

private:
    long long binom(int n, int k)
    {
        long long ans = 1;

        if (k > n - k)
            k = n - k;

        for (int i = 1; i <= k; ++i)
        {
            ans = ans * (n - i + 1) / i;
        }

        return ans;
    }
};