#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        size_t r = grid.size(), c = grid[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

        auto out_range = [](int tr, int lb, int ub)
        {
            return tr < lb || tr >= ub;
        };

        function<int(int, int, int)> dpHelper = [&](int y, int x1, int x2)
        {
            if (out_range(x1, 0, c) || out_range(x2, 0, c) || out_range(y, 0, r))
                return 0;

            if (y == r - 1)
                return x1 == x2 ? grid[y][x1] : (grid[y][x1] + grid[y][x2]);

            int &ans = dp[y][x1][x2];
            if (ans != -1)
                return ans;

            int pick = grid[y][x1] + (x1 != x2) * grid[y][x2];

            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    ans = max(ans, pick + dpHelper(y + 1, x1 + i, x2 + j));
                }
            }

            return ans;
        };

        return dpHelper(0, 0, c - 1);
    }
};