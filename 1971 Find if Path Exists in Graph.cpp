#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    UnionFind(size_t n)
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n);
    }

    void unionByRank(int u, int v)
    {
        int i = find(u);
        int j = find(v);

        if (i == j)
            return;

        if (rank[i] > rank[j])
            swap(i, j);
        parent[i] = j;

        if (rank[i] == rank[j])
            ++rank[j];
    }

    int find(int x)
    {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

private:
    vector<int> parent, rank;
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        UnionFind uf(n);

        for (const auto &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            uf.unionByRank(u, v);
        }

        return uf.find(source) == uf.find(destination);
    }
};

class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int src, int dst)
    {
        if (src == dst)
            return true;

        vector<unordered_set<int>> edgeLists(n);
        for (const auto &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            edgeLists[u].insert(v);
            edgeLists[v].insert(u);
        }
        return dfs(src, dst, edgeLists, vector<bool>(n, false));
    }

private:
    bool dfs(int cur, int dst, vector<unordered_set<int>> &edgeLists, vector<bool> &&visited)
    {
        if (cur == dst)
            return true;

        visited[cur] = true;

        for (const int e : edgeLists[cur])
        {
            if (!visited[e])
            {
                if (dfs(e, dst, edgeLists, move(visited)))
                    return true;
            }
        }

        return false;
    }
};