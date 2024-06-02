#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid.begin()->size();
        int ans = 0;

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1')
                {
                    dfs(grid, i, j);
                    ++ans;
                }

        return ans;
    }

private:
    int m, n;

    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i == m || j < 0 || j == n)
            return;
        if (grid[i][j] != '1')
            return;

        grid[i][j] = '#';

        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
};

// class UnionFind
// {
// public:
//     UnionFind(vector<vector<char>> &grid, int m, int n) : m(m), n(n), nums(0)
//     {
//         for (int i = 0; i < m; ++i)
//         {
//             for (int j = 0; j < n; ++j)
//             {
//                 if (grid[i][j] == '1')
//                     ++nums;
//             }
//         }

//         parents.resize(m * n);
//         iota(parents.begin(), parents.end(), 0);
//     }

//     void unionSets(int node1, int node2)
//     {
//         int root1 = find(node1);
//         int root2 = find(node2);

//         if (root1 != root2)
//         {
//             parents[root2] = root1;
//             --nums;
//         }
//     }

//     int find(int x)
//     {
//         while (parents[x] != x)
//         {
//             parents[x] = parents[parents[x]];
//             x = parents[x];
//         }
//         return x;
//     }

//     const int getNums() const
//     {
//         return nums;
//     }

//     int node(int i, int j)
//     {
//         return i * n + j;
//     }

// private:
//     int m;
//     int n;
//     int nums;
//     vector<int> parents;
// };

// class Solution
// {
// public:
//     int numIslands(vector<vector<char>> &grid)
//     {
//         const int m = grid.size();
//         const int n = grid.begin()->size();
//         UnionFind uf(grid, m, n);

//         for (int i = 0; i < m; ++i)
//         {
//             for (int j = 0; j < n; ++j)
//             {
//                 if (grid[i][j] == '1')
//                 {
//                     int cur = uf.node(i, j);

//                     if (i < (m - 1) && grid[i + 1][j] == '1')
//                         uf.unionSets(cur, uf.node(i + 1, j));

//                     if (i > 0 && grid[i - 1][j] == '1')
//                         uf.unionSets(cur, uf.node(i - 1, j));

//                     if (j < (n - 1) && grid[i][j + 1] == '1')
//                         uf.unionSets(cur, uf.node(i, j + 1));

//                     if (j > 0 && grid[i][j - 1] == '1')
//                         uf.unionSets(cur, uf.node(i, j - 1));
//                 }
//             }
//         }

//         return uf.getNums();
//     }
// };