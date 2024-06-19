#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (bloomDay.size() < static_cast<long>(m) * k)
            return -1;

        const auto minmax = minmax_element(bloomDay.begin(), bloomDay.end());
        int l = *(minmax.first), r = *(minmax.second);

        while (l < r)
        {
            const int mid = (l + r) / 2;
            if (bouquetsMade(bloomDay, k, mid) < m)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }

private:
    int bouquetsMade(const vector<int> &bloomDay, int k, int waiting)
    {
        int cnt = 0, cur = 0;

        for (const int day : bloomDay)
        {
            if (day > waiting)
                cur = 0;
            else if (++cur == k)
            {
                ++cnt;
                cur = 0;
            }
        }

        return cnt;
    }
};
