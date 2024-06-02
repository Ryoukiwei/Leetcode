#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        const int n = nums.size();

        if (nums.front() >= n)
            return n;

        int cnt = n - 1;
        auto nend = nums.end();
        for (auto it = nums.begin() + 1; it != nend; ++it)
        {
            if (*prev(it) < cnt && *it >= cnt)
                return cnt;
            --cnt;
        }

        return -1;
    }
};