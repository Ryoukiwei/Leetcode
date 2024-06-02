#include <bits/stdc++.h>
using namespace std;
using pli = pair<long long, int>;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        priority_queue<int, vector<int>, greater<int>> idle;
        priority_queue<pli, vector<pli>, greater<pli>> busy;
        vector<int> count(n, 0);

        for (int i = 0; i < n; i++)
            idle.push(i);

        sort(meetings.begin(), meetings.end());

        for (auto &meeting : meetings)
        {
            int start = meeting[0], end = meeting[1];
            while (!busy.empty() && busy.top().first <= start)
            {
                idle.push(busy.top().second);
                busy.pop();
            }

            int room;

            if (!idle.empty())
            {
                room = idle.top();
                idle.pop();
                busy.emplace(end, room);
            }
            else
            {
                auto top = busy.top();
                busy.pop();
                room = top.second;
                busy.emplace(top.first + (end - start), room);
            }

            count[room]++;
        }

        return max_element(count.begin(), count.end()) - count.begin();
    }
};