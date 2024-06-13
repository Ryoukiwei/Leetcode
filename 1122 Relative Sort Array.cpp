#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> ans;
        array<int, 1001> cnt;

        for (const int entry : arr1)
        {
            ++cnt[entry];
        }

        for (const int entry : arr2)
        {
            while (cnt[entry]-- > 0)
                ans.emplace_back(entry);
        }

        for (int i = 0; i < 1001; ++i)
        {
            while (cnt[i]-- > 0)
                ans.emplace_back(i);
        }

        return ans;
    }
};