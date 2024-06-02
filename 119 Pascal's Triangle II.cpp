#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ans(rowIndex + 1, 1);

        long long curr = 1;
        for (int i = 1; i < rowIndex; ++i)
        {
            curr *= (rowIndex - i + 1) / i;
            ans[i] = curr;
        }

        return ans;
    }
};
