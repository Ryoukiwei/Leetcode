#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using Graph = unordered_map<int, unordered_set<int>>;

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};

        Graph graph;
        for (const auto &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }

        vector<int> ans;
        ans.reserve(n);

        for (const auto &[parent, children] : graph)
        {
            if (children.size() == 1)
                ans.emplace_back(parent);
        }

        vector<int> temp;
        temp.reserve(n);
        while (n > 2)
        {
            n -= ans.size();
            temp.clear();
            for (const int leaf : ans)
            {
                const int neighbor = *graph[leaf].begin();
                graph[neighbor].erase(leaf);
                if (graph[neighbor].size() == 1)
                    temp.emplace_back(neighbor);
            }

            ans = temp;
        }

        return ans;
    }
};