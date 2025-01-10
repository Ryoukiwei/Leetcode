#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        int cnt[26] = {0};

        for (const auto &b : words2)
        {
            int temp[26] = {0};
            for (char c : b)
            {
                ++temp[c - 'a'];
            }

            for (int i = 0; i < 26; ++i)
            {
                cnt[i] = max(cnt[i], temp[i]);
            }
        }

        vector<string> ans;
        ans.reserve(words1.size());

        for (const auto &a : words1)
        {
            int temp[26] = {0};
            for (char c : a)
            {
                ++temp[c - 'a'];
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; ++i)
            {
                if (temp[i] < cnt[i])
                {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal)
                ans.push_back(a);
        }

        return ans;
    }
};