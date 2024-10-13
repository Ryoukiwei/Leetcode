#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        priority_queue<int, vector<int>, greater<>> minHeap;

        sort(intervals.begin(), intervals.end());

        for (const auto &interval : intervals)
        {
            if (!minHeap.empty() && interval[0] > minHeap.top())
                minHeap.pop();

            minHeap.push(interval[1]);
        }

        return minHeap.size();
    }
};