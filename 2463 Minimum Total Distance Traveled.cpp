#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Solution
{
public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory)
    {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end(), [](auto &a, auto &b)
             { return a[0] < b[0]; });
        const int rSz = robot.size();
        const int fSz = factory.size();

        vector<vector<long long>> memo(rSz + 1, vector<long long>(fSz + 1, -1));
        return dp(robot, factory, 0, 0, memo);
    }

private:
    long long dp(const vector<int> &robot, const vector<vector<int>> &factory, int rIdx, int fIdx, vector<vector<long long>> &memo)
    {
        if (rIdx == robot.size())
            return 0;
        if (fIdx == factory.size())
            return LLONG_MAX;
        if (memo[rIdx][fIdx] != -1)
            return memo[rIdx][fIdx];

        long long minDist = LLONG_MAX;

        minDist = dp(robot, factory, rIdx, fIdx + 1, memo);
        long long distSum = 0;
        const int bound = factory[fIdx][1];
        const int rSz = robot.size();
        for (int k = 0; k < bound && rIdx + k < rSz; ++k)
        {
            distSum += abs(robot[rIdx + k] - factory[fIdx][0]);
            long long next = dp(robot, factory, rIdx + k + 1, fIdx + 1, memo);
            if (next != LLONG_MAX)
                minDist = min(minDist, distSum + next);
        }

        return memo[rIdx][fIdx] = minDist;
    }
};