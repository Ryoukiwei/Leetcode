#include <vector>
#include <deque>
#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
    {
        unordered_map<int, deque<int>> graph;
        unordered_map<int, int> degreeDiff;

        for (const auto &pair : pairs)
        {
            const int start = pair[0], end = pair[1];
            graph[start].push_back(end);
            ++degreeDiff[start];
            --degreeDiff[end];
        }

        int startNode = pairs[0][0];
        for (const auto &[node, deg] : degreeDiff)
        {
            if (deg == 1)
                startNode = node;
        }

        vector<vector<int>> ans;
        ans.reserve(pairs.size());
        function<void(int)> dfs = [&](int node)
        {
            while (!graph[node].empty())
            {
                int next = graph[node].front();
                graph[node].pop_front();
                dfs(next);
                ans.push_back({node, next});
            }
        };

        dfs(startNode);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};