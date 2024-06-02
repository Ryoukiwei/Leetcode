#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n = groupSizes.size();
        vector<vector<int>> ans, record(n + 1);

        for (int i = 0; i < n; i++)
        {
            auto &temp = record[groupSizes[i]];
            temp.push_back(i);

            if (temp.size() == groupSizes[i])
            {
                ans.push_back(temp);
                temp.clear();
            }
        }

        return ans;
    }
};