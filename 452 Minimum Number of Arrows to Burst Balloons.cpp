#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());
        int ans = 1, end = (*points.begin())[1];

        for (const auto &point : points)
        {
            if (point[0] > end)
            {
                end = point[1];
                ans++;
            }
            else
                end = min(end, point[1]);
        }

        return ans;
    }
};