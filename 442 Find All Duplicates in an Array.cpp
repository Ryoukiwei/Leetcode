#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;

        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            while (*it != *(nums.begin() + *it - 1))
                swap(*it, *(nums.begin() + *it - 1));
        }

        int index = 1;
        for (auto it = nums.begin(); it != nums.end(); it++, index++)
        {
            if (*it != index)
                ans.emplace_back(*it);
        }

        return ans;
    }
};
