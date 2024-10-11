#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        const int n = times.size();
        vector<pair<int, int>> in, out;
        for (int i = 0; i < n; ++i)
        {
            in.push_back({times[i][0], i});
            out.push_back({times[i][1], i});
        }

        sort(in.begin(), in.end());
        sort(out.begin(), out.end());

        priority_queue<int, vector<int>, greater<int>> seats;
        for (int i = 0; i < n; ++i)
        {
            seats.push(i);
        }

        vector<int> chairs(n, -1);
        int inIdx = 0, outIdx = 0;
        while (inIdx < n)
        {
            while (outIdx < n && out[outIdx].first <= in[inIdx].first)
                seats.push(chairs[out[outIdx++].second]);

            const int inFriend = in[inIdx].second;
            const int chair = seats.top();
            seats.pop();
            chairs[inFriend] = chair;

            if (inFriend == targetFriend)
                return chair;

            ++inIdx;
        }

        return -1;
    }
};