#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int num = 0;
        for (auto &task : tasks)
        {
            task.emplace_back(num++);
        }

        sort(tasks.begin(), tasks.end());

        using pii = pair<int, int>;
        using ll = long long;
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        int i = 0;
        ll time = 0;
        vector<int> ans;

        while (!minHeap.empty() || i < num)
        {
            if (minHeap.empty())
                time = max(time, (ll)tasks[i][0]);

            while (i < num && tasks[i][0] <= time)
            {
                minHeap.emplace(tasks[i][1], tasks[i][2]);
                i++;
            }

            auto [t, n] = minHeap.top();
            minHeap.pop();
            ans.emplace_back(n);
            time += t;
        }

        return ans;
    }
};