#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid.begin()->size();
        int ans = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                ans = max(ans, helper(grid, i, j));
            }
        }

        return ans;
    }

private:
    array<int, 4> dx = {1, -1, 0, 0};
    array<int, 4> dy = {0, 0, 1, -1};

    int helper(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i == grid.size() || j == grid.begin()->size())
            return 0;
        if (!grid[i][j])
            return 0;

        const int temp = grid[i][j];
        grid[i][j] = 0;
        int maxPath = 0;
        for (int k = 0; k < 4; ++k)
        {
            maxPath = max(maxPath, helper(grid, i + dx[k], j + dy[k]));
        }
        grid[i][j] = temp;

        return maxPath + temp;
    }
};