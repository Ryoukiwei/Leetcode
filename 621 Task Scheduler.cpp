#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int num_tasks = tasks.size();

        if (!n)
            return num_tasks;

        vector<int> cnt(26, 0);

        for (const char task : tasks)
        {
            cnt[task - 'A']++;
        }

        const int maxFreq = *max_element(cnt.begin(), cnt.end());
        const int num_maxFreq = count(cnt.begin(), cnt.end(), maxFreq);
        const int ans = (maxFreq - 1) * (1 + n) + num_maxFreq;

        return max(ans, num_tasks);
    }
};