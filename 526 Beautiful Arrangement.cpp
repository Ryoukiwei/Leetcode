#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countArrangement(int n)
    {
        vector<int> perm(n);
        iota(perm.begin(), perm.end(), 1);
        return helper(n, perm);
    }

private:
    int helper(int n, vector<int> &perm)
    {
        if (!n)
            return 1;

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!(perm[i] % n) || !(n % perm[i]))
            {
                swap(perm[i], perm[n - 1]);
                ans += helper(n - 1, perm);
                swap(perm[i], perm[n - 1]);
            }
        }

        return ans;
    }
};