#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        auto rfirst = make_reverse_iterator(nums.end());
        auto rlast = make_reverse_iterator(nums.begin());
        auto left = is_sorted_until(rfirst, rlast);

        if (left != rlast)
        {
            auto right = upper_bound(rfirst, left, *left);
            iter_swap(left, right);
        }

        reverse(left.base(), nums.end());
    }
};
