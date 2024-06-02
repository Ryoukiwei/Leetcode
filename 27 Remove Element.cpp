#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        auto ans = remove(nums.begin(), nums.end(), val);
        return ans - nums.begin();
    }
};