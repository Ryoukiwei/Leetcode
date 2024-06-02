#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int matrixScore(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        auto column = grid.begin();
        const int n = column->size();
        int ans = m;

        for (auto col = column->begin() + 1; col != column->end(); ++col)
        {
            int cnt = 0;
            for (auto &row : grid)
            {
                cnt += *(row.begin() + (col - column->begin())) == *row.begin();
            }
            ans = ans * 2 + max(cnt, m - cnt);
        }

        return ans;
    }
};