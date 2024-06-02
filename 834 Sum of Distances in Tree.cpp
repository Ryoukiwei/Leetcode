#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    using Tree = vector<unordered_set<int>>;

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        vector<int> ans(n);
        vector<int> subtreeSize(n, 1);
        Tree tree(n);

        for (const auto &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            tree[u].insert(v);
            tree[v].insert(u);
        }

        init(tree, 0, -1, subtreeSize, ans);
        reRoot(tree, 0, -1, subtreeSize, ans);
        return ans;
    }

private:
    int n;

    void init(const Tree &tree, int node, int parent, vector<int> &subtreeSize, vector<int> &ans)
    {
        for (const int child : tree[node])
        {
            if (child != parent)
            {
                init(tree, child, node, subtreeSize, ans);
                subtreeSize[node] += subtreeSize[child];
                ans[node] += ans[child] + subtreeSize[child];
            }
        }
    }

    void reRoot(const Tree &tree, int node, int parent, vector<int> &subtreeSize, vector<int> &ans)
    {
        for (const int child : tree[node])
        {
            if (child != parent)
            {
                ans[child] = ans[node] + n - 2 * subtreeSize[child];
                reRoot(tree, child, node, subtreeSize, ans);
            }
        }
    }
};