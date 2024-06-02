#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int left = 0, right = 0; right < nums.size(); right++)
        {
            if (nums[right])
                swap(nums[right], nums[left++]);
        }
    }
};