#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        const int n = nums.size();
        int cnt[32] = {0};
        int ans = n + 1;

        for (int i = 0, j = 0, currOr = 0; j < n; ++j)
        {
            currOr |= nums[j];
            bitset<32> jbits(nums[j]);
            for (int k = 0; k < 32; ++k)
            {
                if (jbits[k])
                    ++cnt[k];
            }

            while (currOr >= k && i <= j)
            {
                ans = min(ans, j - i + 1);
                bitset<32> ibits(nums[i++]);
                for (int k = 0; k < 32; ++k)
                {
                    if (ibits[k])
                    {
                        if (--cnt[k] == 0)
                            currOr &= ~(1 << k);
                    }
                }
            }
        }

        return ans == n + 1 ? -1 : ans;
    }
};