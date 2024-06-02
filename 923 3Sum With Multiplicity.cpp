#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        const int M = 1e9 + 7;
        int ans = 0;
        unordered_map<int, int> count;

        for (const int a : arr)
            ++count[a];

        for (const auto &[i, x] : count)
            for (const auto &[j, y] : count)
            {
                const int k = target - i - j;
                const auto it = count.find(k);
                if (it == count.cend())
                    continue;
                if (i == j && j == k)
                    ans = (ans + static_cast<long>(x) * (x - 1) * (x - 2) / 6) % M;
                else if (i == j && j != k)
                    ans = (ans + static_cast<long>(x) * (x - 1) / 2 * it->second) % M;
                else if (i < j && j < k)
                    ans = (ans + static_cast<long>(x) * y * it->second) % M;
            }

        return ans;
    }
};