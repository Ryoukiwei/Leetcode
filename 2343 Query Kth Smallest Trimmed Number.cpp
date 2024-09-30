#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;

        for (const auto &query : queries)
        {
            ans.emplace_back(helper(nums, query));
        }

        return ans;
    }

private:
    int helper(const vector<string> &nums, const vector<int> &query)
    {
        const int n = nums.size();
        const int len = nums.begin()->length();
        const int k = query[0];
        const int trim = query[1];

        vector<vector<int>> idxCache(10); // base = 10
        vector<int> curr(n);
        iota(curr.begin(), curr.end(), 0);
        int cnt, prev = 0;

        for (int i = len - trim; i < len; ++i)
        {
            for (auto &cache : idxCache)
            {
                cache.clear();
            }

            for (int idx : curr)
            {
                idxCache[nums[idx][i] - '0'].emplace_back(idx);
            }

            cnt = prev;

            for (int j = 0; j < 10; ++j)
            {
                if (!idxCache[j].empty())
                {
                    prev = cnt;
                    cnt += idxCache[j].size();
                    if (cnt >= k)
                    {
                        curr = idxCache[j];
                        break;
                    }
                }
            }

            if (curr.size() < 2)
                break;
        }

        return curr[k - prev - 1];
    }
};

// class Solution
// {
// public:
//     vector<int> smallestTrimmedNumbers(vector<string> &nums, vector<vector<int>> &queries)
//     {
//         const int n = nums.size();
//         const int len = nums.begin()->length();
//         vector<int> ans;

//         for (const auto &query : queries)
//         {
//             const int k = query[0];
//             const int trim = query[1];

//             vector<pair<string_view, int>> trimmed;
//             for (int i = 0; i < n; ++i)
//             {
//                 string_view trimmed_num = string_view(nums[i]).substr(len - trim);
//                 trimmed.emplace_back(trimmed_num, i);
//             }

//             sort(trimmed.begin(), trimmed.end(), [](const auto &a, const auto &b)
//                  { return a.first < b.first || (a.first == b.first && a.second < b.second); });

//             ans.emplace_back(trimmed[k - 1].second);
//         }

//         return ans;
//     }
// };