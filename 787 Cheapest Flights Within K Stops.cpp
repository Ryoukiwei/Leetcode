#include <bits/stdc++.h>
using namespace std;
using VVP = vector<vector<pair<int, int>>>;

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k)
    {
        VVP graph(n);

        for (const vector<int> &flight : flights)
        {
            const int u = flight[0], v = flight[1], w = flight[2];
            graph[u].emplace_back(v, w);
        }

        return dijkstra(graph, src, dst, k);
    }

private:
    int dijkstra(const VVP &graph, int src, int dst, int k)
    {
        vector<vector<int>> dist(graph.size(), vector<int>(k + 2, INT_MAX));
        using T = tuple<int, int, int>;
        priority_queue<T, vector<T>, greater<T>> minHeap;

        dist[src][k + 1] = 0;
        minHeap.emplace(dist[src][k + 1], src, k + 1);

        while (!minHeap.empty())
        {
            const auto [d, u, stops] = minHeap.top();
            minHeap.pop();

            if (u == dst)
                return d;

            if (!stops)
                continue;

            for (const auto &[v, w] : graph[u])
                if (d + w < dist[v][stops - 1])
                {
                    dist[v][stops - 1] = d + w;
                    minHeap.emplace(dist[v][stops - 1], v, stops - 1);
                }
        }

        return -1;
    }
};

// class Solution
// {
// public:
//     int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
//     {
//         vector<int> dp(n, INT_MAX / 2);
//         dp[src] = 0;
//         int ret = INT_MAX / 2;

//         for (int count = 0; count <= k; count++)
//         {
//             vector<int> temp = dp;
//             for (auto flight : flights)
//             {
//                 int i = flight[0], j = flight[1], p = flight[2];
//                 temp[j] = min(temp[j], dp[i] + p);
//                 if (j == dst)
//                     ret = min(ret, temp[j]);
//             }
//             dp = temp;
//         }

//         return ret >= INT_MAX / 2 ? -1 : ret;
//     }
// };
