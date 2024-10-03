#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        const int n = nums.size();
        const int r = accumulate(nums.begin(), nums.end(), 0LL) % p;

        if (!r)
            return 0;

        unordered_map<int, int> prefixIdx{{0, -1}};
        int rPrefix = 0, ans = n;

        for (int i = 0; i < n; ++i)
        {
            rPrefix = (rPrefix + nums[i]) % p;
            auto it = prefixIdx.find((rPrefix + p - r) % p);

            if (it != prefixIdx.end())
                ans = min(ans, i - it->second);

            prefixIdx[rPrefix] = i;
        }

        return ans != n ? ans : -1;
    }
};