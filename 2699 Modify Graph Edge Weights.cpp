#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using pii = pair<int, int>;
    using G = vector<vector<pii>>;

public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        constexpr int kMax = 2000000000;
        G graph(n);
        for (const auto &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            const int wt = edge[2];
            if (wt != -1)
            {
                graph[u].emplace_back(v, wt);
                graph[v].emplace_back(u, wt);
            }
        }

        int dist_dest = dijkstra(graph, source, destination);
        if (dist_dest < target)
            return {};
        if (dist_dest == target)
        {
            for (auto &edge : edges)
                if (edge[2] == -1)
                    edge[2] = kMax;
            return edges;
        }

        const int size = edges.size();
        for (int i = 0; i < size; ++i)
        {
            const int u = edges[i][0];
            const int v = edges[i][1];
            int &wt = edges[i][2];
            if (wt != -1)
                continue;
            wt = 1;
            graph[u].emplace_back(v, 1);
            graph[v].emplace_back(u, 1);
            dist_dest = dijkstra(graph, source, destination);
            if (dist_dest <= target)
            {
                wt += target - dist_dest;
                for (int j = i + 1; j < size; ++j)
                    if (edges[j][2] == -1)
                        edges[j][2] = kMax;
                return edges;
            }
        }

        return {};
    }

private:
    int dijkstra(G &graph, int s, int t)
    {
        vector<int> dist(graph.size(), INT_MAX);
        priority_queue<pii, vector<pii>, greater<>> minHeap;

        dist[s] = 0;
        minHeap.emplace(dist[s], s);

        while (!minHeap.empty())
        {
            const auto top = minHeap.top();
            minHeap.pop();
            const int d = top.first, u = top.second;
            if (d > dist[u])
                continue;

            for (const auto &edge : graph[u])
            {
                const int v = edge.first, w = edge.second, relax = d + w;
                if (dist[v] > relax)
                {
                    dist[v] = relax;
                    minHeap.emplace(dist[v], v);
                }
            }
        }

        return dist[t];
    }
};