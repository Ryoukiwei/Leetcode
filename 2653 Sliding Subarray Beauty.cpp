#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x)
    {
        vector<int> ans;
        ans.reserve(nums.size() + 1 - k);

        auto nbegin = nums.begin(), nend = nums.end();
        for (auto it = nbegin; it != nend; ++it)
        {
            if (*it < 0)
                ++cnt[*it + 50];

            auto pos = it - k;
            if (pos >= nbegin && *pos < 0)
                --cnt[*pos + 50];

            if (pos + 1 >= nbegin)
                ans.emplace_back(getTheBeauty(x));
        }

        return ans;
    }

private:
    array<int, 50> cnt = {0};

    int getTheBeauty(int x)
    {
        for (int i = 0, sum = 0; i < 50; ++i)
        {
            sum += cnt[i];

            if (!(sum < x))
                return i - 50;
        }

        return 0;
    }
};