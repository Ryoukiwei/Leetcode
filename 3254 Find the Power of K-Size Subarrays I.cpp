#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;

        const int n = nums.size();
        vector<int> ans(n - k + 1, -1);

        for (int i = 0, len = 1; i < n - 1; ++i)
        {
            if (nums[i] + 1 == nums[i + 1])
                ++len;
            else
                len = 1;

            if (len >= k)
                ans[i - k + 2] = nums[i + 1];
        }

        return ans;
    }
};