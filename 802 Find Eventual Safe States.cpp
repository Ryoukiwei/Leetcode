#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        const int n = graph.size();
        vector<State> states(n, State::UNVISITED);
        vector<int> ans;
        ans.reserve(n);

        for (int i = 0; i < n; ++i)
        {
            if (dfs(graph, i, states))
                ans.push_back(i);
        }

        return ans;
    }

private:
    enum class State : char
    {
        UNVISITED,
        VISITING,
        SAFE,
    };

    bool dfs(const vector<vector<int>> &graph, int curr, vector<State> &states)
    {
        if (states[curr] != State::UNVISITED)
            return states[curr] == State::SAFE;

        states[curr] = State::VISITING;
        for (int neighbor : graph[curr])
        {
            if (!dfs(graph, neighbor, states))
                return false;
        }

        states[curr] = State::SAFE;
        return true;
    }
};