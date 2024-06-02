#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using Grid = vector<vector<int>>;
    using Point = pair<int, int>;

public:
    int maximumSafenessFactor(Grid &grid)
    {
        const Grid thiefDist = getThiefDistance(grid);
        int l = 0, r = grid.size() * 2;

        while (l < r)
        {
            const int mid = (l + r) / 2;
            if (hasValidPath(thiefDist, mid))
                l = mid + 1;
            else
                r = mid;
        }

        return l - 1;
    }

private:
    array<int, 4> dx = {1, -1, 0, 0};
    array<int, 4> dy = {0, 0, 1, -1};

    bool hasValidPath(const Grid &thiefDist, int safeness)
    {
        if (thiefDist[0][0] < safeness)
            return false;

        const int n = thiefDist.size();
        queue<Point> q{{{0, 0}}};
        vector<vector<bool>> visited(n, vector<bool>(n));
        visited[0][0] = true;

        while (!q.empty())
        {
            const auto [i, j] = q.front();
            q.pop();

            if (thiefDist[i][j] < safeness)
                continue;
            if (i == n - 1 && j == n - 1)
                return true;

            for (int k = 0; k < 4; ++k)
            {
                const int x = i + dx[k];
                const int y = j + dy[k];

                if (x < 0 || x == n || y < 0 || y == n)
                    continue;
                if (visited[x][y])
                    continue;

                q.emplace(x, y);
                visited[x][y] = true;
            }
        }

        return false;
    }

    Grid getThiefDistance(const Grid &grid)
    {
        const int n = grid.size();
        Grid thiefDist(n, vector<int>(n));
        queue<Point> q;
        vector<vector<bool>> visited(n, vector<bool>(n));

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }

        for (int dist = 0; !q.empty(); ++dist)
        {
            int qsize = q.size();
            while (qsize--)
            {
                const auto [i, j] = q.front();
                q.pop();
                thiefDist[i][j] = dist;

                for (int k = 0; k < 4; ++k)
                {
                    const int x = i + dx[k];
                    const int y = j + dy[k];

                    if (x < 0 || x == n || y < 0 || y == n)
                        continue;
                    if (visited[x][y])
                        continue;

                    q.emplace(x, y);
                    visited[x][y] = true;
                }
            }
        }

        return thiefDist;
    }
};