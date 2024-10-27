#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        const int m = matrix.size();
        const int n = matrix.begin()->size();
        vector<vector<int>> dp(m, vector<int>(n));
        int ans = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!(i && j))
                    dp[i][j] = matrix[i][j];
                else if (matrix[i][j] == 1)
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

                ans += dp[i][j];
            }
        }

        return ans;
    }
};