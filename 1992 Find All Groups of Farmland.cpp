#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        m = land.size();
        n = land.begin()->size();
        vector<vector<int>> ans;
        ans.reserve((m * n + 1) / 2);

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (land[i][j] == 1)
                {
                    int u = i, v = j;
                    dfs(land, i, j, u, v);
                    ans.emplace_back(vector<int>{i, j, u, v});
                }
            }
        }

        return ans;
    }

private:
    int m, n;

    void dfs(vector<vector<int>> &land, int i, int j, int &u, int &v)
    {
        if (i == m || j == n)
            return;

        if (land[i][j] != 1)
            return;

        land[i][j] = -1;

        u = max(u, i);
        v = max(v, j);
        dfs(land, i + 1, j, u, v);
        dfs(land, i, j + 1, u, v);
    }
};