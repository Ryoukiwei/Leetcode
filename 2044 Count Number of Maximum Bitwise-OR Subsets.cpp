#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        const int maxOr = accumulate(nums.begin(), nums.end(), 0, bit_or<>());
        int ans = 0;

        helper(nums, 0, 0, maxOr, ans);

        return ans;
    }

private:
    void helper(const vector<int> &nums, int i, int curr, const int &maxOr, int &ans)
    {
        if (i == nums.size())
        {
            if (curr == maxOr)
                ++ans;
            return;
        }

        helper(nums, i + 1, curr, maxOr, ans);
        helper(nums, i + 1, curr | nums[i], maxOr, ans);
    }
};