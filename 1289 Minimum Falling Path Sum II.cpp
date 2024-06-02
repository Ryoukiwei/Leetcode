#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        const int n = grid.size();
        if (n == 1)
            return grid[0][0];

        for (int i = 1; i < n; ++i)
        {
            const auto &[min1, min2] = getMinTwice(grid[i - 1]);
            for (int j = 0; j < n; ++j)
            {
                grid[i][j] += (grid[i - 1][j] != min1) ? min1 : min2;
            }
        }

        return *min_element(grid.back().begin(), grid.back().end());
    }

private:
    pair<int, int> getMinTwice(const vector<int> &row)
    {
        vector<int> result(row.begin(), row.end());
        sort(result.begin(), result.end());
        return {*result.begin(), *(result.begin() + 1)};
    }
};