#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int ans = -1;
        unordered_set<int> visited;

        for (const int num : nums)
        {
            if (visited.count(-num))
                ans = max(ans, abs(num));
            else
                visited.insert(num);
        }

        return ans;
    }
};