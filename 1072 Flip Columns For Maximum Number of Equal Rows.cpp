#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
    {
        unordered_map<string, int> rowPattern;

        for (auto &row : matrix)
        {
            string str, complement;

            for (int digit : row)
            {
                str += to_string(digit);
                complement += to_string(!digit);
            }

            rowPattern[str]++;
            rowPattern[complement]++;
        }

        auto compare = [](const auto &a, const auto &b)
        {
            return a.second < b.second;
        };

        auto it = max_element(rowPattern.begin(), rowPattern.end(), compare);

        return it->second;
    }
};
