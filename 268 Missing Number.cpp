#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        size_t n = nums.size();
        const int expected = n * (n + 1) / 2;
        int sum = 0;

        for (int num : nums)
        {
            sum += num;
        }

        return expected - sum;
    }
};