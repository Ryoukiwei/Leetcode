#include <bits/stdc++.h>
using namespace std;

enum class Color
{
    white,
    gray,
    black

};

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        colors.fill(Color::white);
        int n = graph.size();

        for (int i = 0; i < n; ++i)
        {
            if (colors[i] == Color::white && !bfs(graph, i))
                return false;
        }

        return true;
    }

private:
    array<Color, 100> colors;

    bool bfs(const vector<vector<int>> &graph, int s)
    {
        colors[s] = Color::gray;

        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            const int u = q.front();
            q.pop();

            for (const int v : graph[u])
            {
                if (colors[v] == colors[u])
                    return false;

                if (colors[v] == Color::white)
                {
                    colors[v] = (colors[u] == Color::gray) ? Color::black : Color::gray;
                    q.push(v);
                }
            }
        }

        return true;
    }
};