#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int ans = 0;
        vector<pair<int, int>> jobs;

        const int n = difficulty.size();
        for (int i = 0; i < n; ++i)
        {
            jobs.emplace_back(difficulty[i], profit[i]);
        }

        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());

        int maxProfit = 0;
        auto it = jobs.begin(), end = jobs.end();

        for (const int ability : worker)
        {
            while (it != end && it->first <= ability)
            {
                maxProfit = max(maxProfit, it->second);
                ++it;
            }

            ans += maxProfit;
        }

        return ans;
    }
};