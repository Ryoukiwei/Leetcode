#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        const int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        vector<int> s;
        s.reserve(n);

        s.push_back(nums.front());
        for (int i = 1; i < n; ++i)
        {
            const int pos = lower_bound(s.begin(), s.end(), nums[i]) - s.begin();
            if (pos == s.size())
                s.push_back(nums[i]);
            else
                s[pos] = nums[i];

            left[i] = pos + 1;
        }

        s.clear();
        s.push_back(nums[n - 1]);
        for (int i = n - 2; i >= 0; --i)
        {
            const int pos = lower_bound(s.begin(), s.end(), nums[i]) - s.begin();
            if (pos == s.size())
                s.push_back(nums[i]);
            else
                s[pos] = nums[i];

            right[i] = pos + 1;
        }

        int ans = n;
        for (int i = 1; i < n - 1; ++i)
        {
            if (left[i] > 1 && right[i] > 1)
                ans = min(ans, n - (left[i] + right[i] - 1));
        }

        return ans;
    }
};