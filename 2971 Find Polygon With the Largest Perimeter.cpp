#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        sort(nums.begin(), nums.end(), greater<int>());

        for (int num : nums)
        {
            sum -= num;

            if (sum > num)
                return sum + num;
        }

        return -1;
    }
};