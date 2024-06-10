#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        int ans = 0, curr = 1;
        array<int, 101> cnt;

        for (const int height : heights)
        {
            ++cnt[height];
        }

        for (const int height : heights)
        {
            while (!cnt[curr])
                ++curr;

            if (height != curr)
                ++ans;

            --cnt[curr];
        }

        return ans;
    }
};

// class Solution
// {
// public:
//     int heightChecker(vector<int> &heights)
//     {
//         vector<int> temp = heights;
//         sort(temp.begin(), temp.end());
//         const int n = temp.size();
//         int ans = 0;

//         for (int i = 0; i < n; ++i)
//         {
//             if (temp[i] != heights[i])
//                 ++ans;
//         }

//         return ans;
//     }
// };