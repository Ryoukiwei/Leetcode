#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        const size_t rowSize = grid.size(), colSize = grid.begin()->size();
        int ans = 0;

        for (size_t i = 0; i < rowSize; ++i)
        {
            for (size_t j = 0; j < colSize; ++j)
            {
                if (!grid[i][j])
                    continue;

                ans += 4;

                if (i && grid[i - 1][j])
                    ans -= 2;
                if (j && grid[i][j - 1])
                    ans -= 2;
            }
        }

        return ans;
    }
};

class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {

        rowSize = grid.size();
        colSize = grid.begin()->size();
        int ans = 0;

        for (size_t i = 0; i < rowSize; ++i)
        {
            for (size_t j = 0; j < colSize; ++j)
            {
                if (grid[i][j])
                {
                    dfs(grid, i, j, ans);
                    return ans;
                }
            }
        }

        return ans;
    }

private:
    size_t rowSize, colSize;

    void dfs(vector<vector<int>> &grid, int i, int j, int &ans)
    {
        if (i < 0 || i >= rowSize || j < 0 || j >= colSize)
        {
            ++ans;
            return;
        }

        if (!grid[i][j])
        {
            ++ans;
            return;
        }

        if (grid[i][j] == -1)
            return;

        grid[i][j] = -1;

        dfs(grid, i + 1, j, ans); // Down
        dfs(grid, i - 1, j, ans); // Up
        dfs(grid, i, j + 1, ans); // Right
        dfs(grid, i, j - 1, ans); // Left
    };
};