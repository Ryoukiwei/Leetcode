#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int idx = 0;

        for (auto interval : intervals)
        {
            if (interval[0] > newInterval[1])
                ans.emplace_back(interval);
            else if (interval[1] < newInterval[0])
            {
                ans.emplace_back(interval);
                idx++;
            }
            else
                newInterval = {min(newInterval[0], interval[0]), max(newInterval[1], interval[1])};
        }

        ans.insert(ans.begin() + idx, newInterval);
        return ans;
    }
};