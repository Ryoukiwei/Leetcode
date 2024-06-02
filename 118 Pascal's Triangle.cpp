#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        ans.emplace_back(1, 1);

        for (int i = 0; i < numRows - 1; i++)
        {
            vector<int> temp;
            temp.emplace_back(1);

            for (int j = 0; j < ans[i].size() - 1; j++)
            {
                temp.emplace_back(ans[i][j] + ans[i][j + 1]);
            }

            temp.emplace_back(1);
            ans.emplace_back(temp);
        }

        return ans;
    }
};