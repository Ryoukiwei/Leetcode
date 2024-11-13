#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        sort(nums.begin(), nums.end());
        return countNotGreater(nums, upper) - countNotGreater(nums, lower - 1);
    }

private:
    long long countNotGreater(const vector<int> &nums, int target)
    {
        long long ans = 0;
        for (auto begin = nums.begin(), end = prev(nums.end()); begin < end; ++begin)
        {
            while (begin < end && *begin + *end > target)
                --end;
            ans += end - begin;
        }

        return ans;
    }
};