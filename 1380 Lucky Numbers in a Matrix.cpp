#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        for (const auto &row : matrix)
        {
            auto min = min_element(row.begin(), row.end());
            if (*min == maxInCol(matrix, distance(row.begin(), min)))
                return {*min};
        }

        return {};
    }

private:
    int maxInCol(vector<vector<int>> &matrix, int j)
    {
        int ans = 0;
        const int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            ans = max(ans, matrix[i][j]);
        }

        return ans;
    }
};