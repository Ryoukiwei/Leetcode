#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        long long sum = 0;
        int cnt = 0;
        int delta = INT_MAX;

        for (const int num : nums)
        {
            const int xorNum = num ^ k;
            sum += max(num, xorNum);
            cnt += (xorNum > num);
            delta = min(delta, abs(num - xorNum));
        }

        return (cnt % 2) ? sum - delta : sum;
    }
};