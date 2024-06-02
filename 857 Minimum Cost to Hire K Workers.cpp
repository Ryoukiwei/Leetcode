#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k)
    {
        double ans = DBL_MAX;
        int totalQlt = 0;
        vector<pair<double, int>> workers;
        priority_queue<int> maxHeap;

        const int n = quality.size();
        for (int i = 0; i < n; ++i)
        {
            workers.emplace_back(static_cast<double>(wage[i]) / quality[i], quality[i]);
        }

        sort(workers.begin(), workers.end());

        for (const auto &[wpq, qlt] : workers)
        {
            maxHeap.push(qlt);
            totalQlt += qlt;

            if (maxHeap.size() > k)
            {
                totalQlt -= maxHeap.top();
                maxHeap.pop();
            }

            if (maxHeap.size() == k)
            {
                ans = min(ans, totalQlt * wpq);
            }
        }

        return ans;
    }
};