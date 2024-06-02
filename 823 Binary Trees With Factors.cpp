#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {
        const long MODULO = 1e9 + 7;
        unordered_map<int, long> dp;
        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            dp[arr[i]] = 1;

            for (int j = 0; j < i; j++)
            {
                int temp = arr[i] / arr[j];
                if (!(arr[i] % arr[j]) && dp.count(temp))
                    dp[arr[i]] += (dp[arr[j]] * dp[temp]) % MODULO;
            }
        }

        long ans = 0;
        for (const auto &kv : dp)
        {
            ans += kv.second;
        }

        return ans % MODULO;
    }
};