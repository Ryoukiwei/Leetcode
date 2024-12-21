#include <vector>
using namespace std;

struct Graph
{
    int numNode;
    vector<vector<int>> adjList;

    Graph(int n, const vector<vector<int>> &edges) : numNode(n), adjList(n)
    {
        for (const auto &edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
    }
};

class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        Graph g(n, edges);

        int ans = 0;
        dfs(g, 0, -1, values, k, ans);
        return ans;
    }

private:
    long long dfs(const Graph &g, int u, int prev, const vector<int> &values, const int k, int &ans)
    {
        long long sum = values[u];

        for (const int v : g.adjList[u])
        {
            if (v != prev)
                sum += dfs(g, v, u, values, k, ans);
        }

        if (sum % k == 0)
            ++ans;

        return sum;
    }
};