#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int chalkReplacer(vector<int> &chalk, int k)
    {
        k %= accumulate(chalk.begin(), chalk.end(), 0L);

        if (k == 0)
            return 0;

        const int n = chalk.size();
        for (int i = 0; i < n; ++i)
        {
            k -= chalk[i];
            if (k < 0)
                return i;
        }

        throw;
    }
};