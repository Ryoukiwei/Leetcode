#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int cost;
    int x;
    int y;

    Edge() : cost(0), x(0), y(0) {}
    Edge(int cost, int x, int y) : cost(cost), x(x), y(y) {}

    bool operator<(const Edge &e) const { return cost < e.cost; }
    Edge &operator=(const Edge &e)
    {
        if (this != &e)
        {
            cost = e.cost;
            x = e.x;
            y = e.y;
        }
        return *this;
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        size_t n = points.size();
        vector<Edge> edge(n * (n - 1) / 2);

        for (int i = 0, k = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x1 = points[i][0], x2 = points[j][0];
                int y1 = points[i][1], y2 = points[j][1];
                int d = abs(x1 - x2) + abs(y1 - y2);
                edge[k++] = Edge(d, i, j);
            }
        }

        sort(edge.begin(), edge.end());

        vector<int> p(n), rank(n, 0);
        iota(p.begin(), p.end(), 0); // 填入遞增
        int ans = 0, count = 0;

        for (auto &e : edge)
        {
            int rx = find(p, e.x), ry = find(p, e.y);

            if (rx == ry)
                continue; // 兩邊集合一樣深
            ans += e.cost;

            if (rank[rx] < rank[ry])
                swap(rx, ry);
            p[rx] = ry; // 合併
            rank[ry] += (rank[rx] == rank[rx]);

            if (++count == n - 1)
                break;
        }

        return ans;
    }

private:
    // Disjoint Set Union -- find()
    int find(vector<int> &parent, int x)
    {
        while (parent[x] != x) // 當 x 並非集合之根元素
        {
            int temp = parent[x];
            parent[x] = parent[parent[x]];
            x = temp;
        }

        return x;
    }
};
