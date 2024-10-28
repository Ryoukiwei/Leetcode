#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
using namespace std;

constexpr int MAX = 100000;
const int ubound = floor(sqrt(MAX));
bitset<MAX + 1> bs;

class Solution
{
public:
    int longestSquareStreak(vector<int> &nums)
    {
        bs.reset();
        int minNum = MAX;

        for (int num : nums)
        {
            bs[num] = 1;
            minNum = min(minNum, num);
        }

        int ans = -1;
        for (int i = minNum; i <= ubound; i = bs._Find_next(i))
        {
            if (!bs[i])
                continue;
            bs[i] = 0;

            int streak = 1;
            long long num = static_cast<long long>(i) * i;

            while (num <= MAX && bs[num])
            {
                bs[num] = 0;
                ++streak;
                num *= num;
            }

            if (streak >= 2)
                ans = max(ans, streak);
        }

        return ans;
    }
};