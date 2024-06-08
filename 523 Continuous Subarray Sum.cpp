#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     bool checkSubarraySum(vector<int> &nums, int k)
//     {
//         const int n = nums.size();
//         if (n < 2)
//             return false;

//         int sum = 0;
//         unordered_map<int, int> idx{{0, -1}};

//         for (int i = 0; i < n; ++i)
//         {
//             sum += nums[i];

//             if (k)
//                 sum %= k;

//             const auto it = idx.find(sum);
//             if (it != idx.cend())
//             {
//                 if (i - it->second >= 2)
//                     return true;
//             }
//             else
//                 idx[sum] = i;
//         }

//         return false;
//     }
// };

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        if (nums.size() < 2)
            return false;

        auto begin = nums.begin(), end = nums.end();
        auto l = begin, r = next(begin);
        int sum = *l;

        while (r != end)
        {
            sum += *r;

            if (!(sum % k))
                return true;

            if (*r == *prev(r) && !(*r))
                return true;

            int temp = sum;
            l = begin;
            while ((r - l) > 1 && temp >= k)
            {
                temp -= *l++;

                if (!(temp % k))
                    return true;
            }

            ++r;
        }

        return false;
    }
};