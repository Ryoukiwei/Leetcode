#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        const int xorNums = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        return __builtin_popcount(xorNums ^ k);
    }
};