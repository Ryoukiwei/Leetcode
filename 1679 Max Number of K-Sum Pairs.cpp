#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int ans = 0;
        unordered_map<int, int> numsMap;

        for (int num : nums)
        {
            numsMap[num]++;
        }

        for (int num : nums)
        {
            if (numsMap[num] < 1 || numsMap[k - num] < 1 + (num * 2 == k))
                continue;

            numsMap[num]--;
            numsMap[k - num]--;
            ans++;
        }

        return ans;
    }
};