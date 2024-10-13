#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        auto comp = [&](const T &a, const T &b)
        {
            return a.data > b.data;
        };
        priority_queue<T, vector<T>, decltype(comp)> minHeap(comp);
        const int n = nums.size();
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for (int i = 0; i < n; ++i)
        {
            const int num = nums[i][0];
            minHeap.emplace(i, 0, num);
            minVal = min(minVal, num);
            maxVal = max(maxVal, num);
        }

        int ansMin = minVal, ansMax = maxVal;

        while (minHeap.size() == n)
        {
            const auto [i, j, _] = minHeap.top();
            minHeap.pop();
            if (j + 1 < nums[i].size())
            {
                const int nextVal = nums[i][j + 1];
                minHeap.emplace(i, j + 1, nextVal);
                minVal = minHeap.top().data;
                maxVal = max(maxVal, nextVal);

                if (maxVal - minVal < ansMax - ansMin)
                {
                    ansMin = minVal;
                    ansMax = maxVal;
                }
            }
        }

        return {ansMin, ansMax};
    }

private:
    struct T
    {
        int i;
        int j;
        int data;

        T(int i, int j, int data) : i(i), j(j), data(data) {}
    };
};