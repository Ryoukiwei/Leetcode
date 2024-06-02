#include <bits/stdc++.h>
using namespace std;

class T
{
public:
    int d;
    int x;
    int y;

    T(int d, int x, int y) : d(d), x(x), y(y) {}

    bool operator>(const T &other) const
    {
        return d > other.d;
    }
};

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &heights) // Dijkstra (like BFS)
    {
        size_t m = heights.size(), n = heights[0].size();
        vector<vector<int>> diff(m, vector<int>(n, INT_MAX));
        priority_queue<T, vector<T>, greater<T>> minHeap;

        minHeap.emplace(0, 0, 0);
        diff[0][0] = 0;

        while (!minHeap.empty())
        {
            T top = minHeap.top();
            int cost = top.d;
            int x = top.x;
            int y = top.y;
            minHeap.pop();

            if (x == m - 1 && y == n - 1)
                break;

            for (int i = 0; i < 4; i++)
            {
                int cx = x + dx[i];
                int cy = y + dy[i];

                if (cx >= 0 && cy >= 0 && cx < m && cy < n)
                {
                    int maxCost = max(diff[x][y], abs(heights[x][y] - heights[cx][cy]));
                    if (maxCost < diff[cx][cy]) // 如果還能再變更小 就能更新
                    {
                        diff[cx][cy] = maxCost;
                        minHeap.emplace(maxCost, cx, cy);
                    }
                }
            }
        }

        return diff[m - 1][n - 1];
    }

private:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
};