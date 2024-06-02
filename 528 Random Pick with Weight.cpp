#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution(vector<int> &w) : sum(), total(0)
    {
        sum.reserve(w.size());
        for (const int weight : w)
        {
            total += weight;
            sum.emplace_back(total);
        }
    }

    int pickIndex()
    {
        const int target = rand() % sum.back();
        auto l = sum.begin(), r = sum.end();

        while (l < r)
        {
            auto mid = l + (r - l) / 2;
            if (!(*mid > target))
                l = mid + 1;
            else
                r = mid;
        }

        return l - sum.begin();
    }

private:
    vector<int> sum;
    int total;
};