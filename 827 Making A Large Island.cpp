#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        vector<int> islandSize;
        islandSize.reserve(n / 2);
        int label = 2, ans = 0;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    islandSize.push_back(dfs(grid, i, j, label++));
                    ans = max(ans, islandSize.back());
                }
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 0)
                    ans = max(ans, connectIslands(grid, islandSize, i, j));
            }
        }

        return ans;
    }

private:
    static constexpr array<array<int, 2>, 4> directions = {{
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
    }};

    bool isBounded(int ordX, int ordY, int n) noexcept
    {
        return ordX >= 0 && ordY >= 0 && ordX < n && ordY < n;
    }

    int dfs(vector<vector<int>> &grid, int x, int y, int label)
    {
        const int n = grid.size();
        grid[x][y] = label;
        int size = 1;

        for (const auto direction : directions)
        {
            const int ordX = x + direction[0];
            const int ordY = y + direction[1];

            if (isBounded(ordX, ordY, n) && grid[ordX][ordY] == 1)
                size += dfs(grid, ordX, ordY, label);
        }

        return size;
    }

    int connectIslands(vector<vector<int>> &grid, vector<int> &islandSize, int x, int y)
    {
        const int n = grid.size();
        int visited[4] = {0};
        int newSize = 1, directIdx = 0;

        for (const auto direction : directions)
        {
            const int ordX = x + direction[0];
            const int ordY = y + direction[1];
            if (!isBounded(ordX, ordY, n))
                continue;

            const int label = grid[ordX][ordY];
            if (label > 1)
            {
                bool found = false;

                for (int i = 0; i < directIdx; ++i)
                {
                    if (visited[i] == label)
                    {
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    visited[directIdx++] = label;
                    newSize += islandSize[label - 2];
                }
            }
        }

        return newSize;
    }
};