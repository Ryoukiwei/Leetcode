#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;

class DisjointSet
{
public:
    DisjointSet(size_t n) : parent(n), rank(n)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    void unionSet(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
            return;

        if (rank[rootX] > rank[rootY])
            swap(rootX, rootY);
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY])
            ++rank[rootX];
    }

    int find(int x) { return parent[x] == x ? parent[x] : parent[x] = find(parent[x]); }

private:
    vector<int> parent;
    vector<int> rank;
};

enum class Color : char
{
    UNCOLORED,
    BLUE,
    RED,
};

class Solution
{
public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(n);
        DisjointSet uf(n);

        for (const auto &edge : edges)
        {
            const int u = edge[0] - 1;
            const int v = edge[1] - 1;
            graph[u].push_back(v);
            graph[v].push_back(u);
            uf.unionSet(u, v);
        }

        vector<vector<int>> components(n);
        vector<Color> nodeColor(n, Color::UNCOLORED);

        for (int i = 0; i < n; ++i)
        {
            const int root = uf.find(i);
            if (nodeColor[i] == Color::UNCOLORED)
            {
                if (!dfs(i, Color::BLUE, graph, nodeColor, components[root]))
                    return -1;
            }
        }

        int ans = 0;
        for (const auto &component : components)
        {
            if (!component.empty())
                ans += bfs(component, graph);
        }

        return ans;
    }

private:
    bool dfs(int node, Color color, const vector<vector<int>> &graph, vector<Color> &nodeColor, vector<int> &component)
    {
        nodeColor[node] = color;
        component.push_back(node);

        for (int neighbor : graph[node])
        {
            if (nodeColor[neighbor] == color)
                return false;
            if (nodeColor[neighbor] == Color::UNCOLORED && !dfs(neighbor, color == Color::BLUE ? Color::RED : Color::BLUE, graph, nodeColor, component))
                return false;
        }

        return true;
    }

    int bfs(const vector<int> &component, const vector<vector<int>> &graph)
    {
        int maxDepth = 0;
        for (int node : component)
        {
            queue<int> q;
            vector<int> depth(graph.size(), -1);
            q.push(node);
            depth[node] = 1;

            int level = 1;
            while (!q.empty())
            {
                const int u = q.front();
                q.pop();

                for (int v : graph[u])
                {
                    if (depth[v] == -1)
                    {
                        q.push(v);
                        depth[v] = depth[u] + 1;
                        level = max(level, depth[v]);
                    }
                }
            }

            maxDepth = max(maxDepth, level);
        }

        return maxDepth;
    }
};