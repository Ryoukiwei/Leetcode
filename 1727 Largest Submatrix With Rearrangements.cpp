#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        size_t m = matrix.size(), n = matrix[0].size();

        for (int j = 0; j < n; j++)
        {
            for (int i = 1; i < m; i++)
            {
                if (matrix[i][j])
                    matrix[i][j] += matrix[i - 1][j];
            }
        }

        int ans = 0;
        for (auto &row : matrix)
        {
            sort(row.begin(), row.end(), greater());
            for (int j = 0; j < n; j++)
            {
                if (!row[j])
                    break;
                ans = max(ans, (j + 1) * row[j]);
            }
        }

        return ans;
    }
};