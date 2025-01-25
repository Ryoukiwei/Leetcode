#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        vector<int> ans(nums.size());
        vector<vector<Entry>> groups;

        for (const Entry &entry : getEntry(nums))
        {
            if (groups.empty() || entry.num - groups.back().back().num > limit)
                groups.push_back({entry}); // Create a new group
            else
                groups.back().push_back(entry); // Append to the existing group
        }

        for (const auto &group : groups)
        {
            const int n = group.size();
            vector<int> nums, indices;
            nums.reserve(n);
            indices.reserve(n);
            for (const auto &entry : group)
            {
                nums.push_back(entry.num);
                indices.push_back(entry.idx);
            }

            sort(indices.begin(), indices.end());
            for (int i = 0; i < n; ++i)
            {
                ans[indices[i]] = nums[i];
            }
        }

        return ans;
    }

private:
    struct Entry
    {
        int num, idx;

        friend bool operator<(const Entry &lhs, const Entry &rhs)
        {
            return lhs.num != rhs.num ? lhs.num < rhs.num : lhs.idx < rhs.idx;
        }
    };

    vector<Entry> getEntry(const vector<int> &nums)
    {
        const int n = nums.size();
        vector<Entry> res;
        res.reserve(n);
        for (int i = 0; i < n; ++i)
        {
            res.emplace_back(nums[i], i);
        }

        sort(res.begin(), res.end());
        return res;
    }
};