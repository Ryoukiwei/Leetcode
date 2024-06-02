#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> numsMap;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];

            if (numsMap.find(temp) != numsMap.end())
                return {numsMap[temp], i};

            numsMap[nums[i]] = i;
        }

        return {};
    }
};
