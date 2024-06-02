#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> &temp = mat;
        vector<int> ans;

        for (int row = 0; row < temp.size(); row++)
            temp[row].push_back(row);

        sort(temp.begin(), temp.end());

        for (int i = 0; i < k; i++)
            ans.push_back(temp[i].back());

        return ans;
    }

    // vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    // {
    //     size_t m = mat.size();

    //     auto compare = [&mat](int a, int b)
    //     {
    //         int strengthA = count(mat[a].begin(), mat[a].end(), 1);
    //         int strengthB = count(mat[b].begin(), mat[b].end(), 1);

    //         if (strengthA != strengthB)
    //             return strengthA < strengthB;
    //         else
    //             return a < b;
    //     };

    //     vector<int> row(m);
    //     iota(row.begin(), row.end(), 0);
    //     sort(row.begin(), row.end(), compare);

    //     vector<int> ans(row.begin(), row.begin() + k);

    //     return ans;
    // }
};
