#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class DisjointSet
{
public:
    DisjointSet(size_t n) : parent(n), rank(n)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    bool unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return false;

        if (rank[rootX] > rank[rootY])
            swap(rootX, rootY);
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY])
            ++rank[rootX];
        return true;
    }

    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }

private:
    vector<int> parent;
    vector<int> rank;
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        DisjointSet uf(edges.size() + 1);

        for (const auto &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            if (!uf.unionSet(u, v))
                return edge;
        }

        throw;
    }
};