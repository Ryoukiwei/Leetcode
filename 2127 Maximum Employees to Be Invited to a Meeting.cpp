#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        const int n = favorite.size();
        vector<Node> nodes(n);

        for (int u = 0; u < n; ++u)
        {
            ++nodes[favorite[u]].indeg;
        }

        queue<int> q;
        for (int u = 0; u < n; ++u)
        {
            if (!nodes[u].indeg)
                q.push(u);
        }

        while (!q.empty())
        {
            const int u = q.front();
            q.pop();
            const int v = favorite[u];

            nodes[v].dist = max(nodes[v].dist, nodes[u].dist + 1);
            if (--nodes[v].indeg == 0)
                q.push(v);
        }

        int maxCycle = 0, maxChain = 0;

        for (int u = 0; u < n; ++u)
        {
            if (!nodes[u].indeg)
                continue;

            int lenCycle = 0;
            int v = u;
            while (nodes[v].indeg)
            {
                nodes[v].indeg = 0; // visited
                ++lenCycle;
                v = favorite[v];
            }

            if (lenCycle == 2)
                maxChain += nodes[u].dist + nodes[favorite[u]].dist;
            else
                maxCycle = max(maxCycle, lenCycle);
        }

        return max(maxCycle, maxChain);
    }

private:
    struct Node
    {
        int indeg, dist;
        Node() : indeg(0), dist(1) {}
    };
};