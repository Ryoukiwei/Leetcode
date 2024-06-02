#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        const int n = matrix[0].size();
        int ans = 0;
        vector<DPElement> dp(n, DPElement(n));

        for (const auto &rows : matrix)
        {
            updateDP(rows, dp);
            updateMaxArea(ans, dp);
        }

        return ans;
    }

private:
    class DPElement
    {
    public:
        int height;
        int left;
        int right;

        DPElement(int n) : height(0), left(0), right(n) {}

        int area() const
        {
            return (right - left) * height;
        }
    };

    void updateDP(const vector<char> &rows, vector<DPElement> &dp)
    {
        const int n = dp.size();
        int cur = 0;
        for (int j = 0; j < n; ++j)
        {
            if (rows[j] == '1')
            {
                ++dp[j].height;
                dp[j].left = max(dp[j].left, cur);
            }
            else
            {
                dp[j].height = 0;
                dp[j].left = 0;
                cur = j + 1;
            }
        }

        cur = n;
        for (int j = n - 1; j >= 0; --j)
        {
            if (rows[j] == '1')
                dp[j].right = min(dp[j].right, cur);
            else
            {
                dp[j].right = n;
                cur = j;
            }
        }
    }

    void updateMaxArea(int &ans, const vector<DPElement> &dp)
    {
        for (const auto &element : dp)
        {
            ans = max(ans, element.area());
        }
    }
};