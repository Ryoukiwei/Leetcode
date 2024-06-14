#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     int minIncrementForUnique(vector<int> &nums)
//     {
//         int ans = 0;
//         sort(nums.begin(), nums.end());
//         auto it = next(nums.begin()), end = nums.end();

//         for (it; it != end; ++it)
//         {
//             if (!(*prev(it) < *it))
//             {
//                 ans += *prev(it) - *it + 1;
//                 *it = *prev(it) + 1;
//             }
//         }

//         return ans;
//     }
// };

class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        auto minmax = minmax_element(nums.begin(), nums.end());
        const int n = nums.size(), MIN = *minmax.first, MAX = *minmax.second;

        vector<int> freq(MAX - MIN + n + 1);

        for (const int num : nums)
        {
            ++freq[num - MIN];
        }

        auto it = freq.begin(), end = freq.end();
        int ans = 0;

        for (it; it != end; ++it)
        {
            if (*it > 0)
            {
                const int extra = *it - 1;
                *next(it) += extra;
                ans += extra;
            }
        }

        return ans;
    }
};