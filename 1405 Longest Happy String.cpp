#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        int cnt[3] = {a, b, c};
        char chars[3] = {'a', 'b', 'c'};
        const int n = a + b + c;
        string ans;

        for (int i = 0; i < n; ++i)
        {
            int idx = -1;
            for (int j = 0; j < 3; ++j)
            {
                if (cnt[j] > 0)
                {
                    if (idx == -1 || cnt[j] > cnt[idx])
                        idx = j;
                }
            }

            const int len = ans.length();
            if (len >= 2 && ans.back() == chars[idx] && ans[len - 2] == chars[idx])
            {
                int nextIdx = -1;
                for (int j = 0; j < 3; ++j)
                {
                    if (cnt[j] > 0 && chars[j] != chars[idx])
                    {
                        if (nextIdx == -1 || cnt[j] > cnt[nextIdx])
                            nextIdx = j;
                    }
                }

                if (nextIdx == -1)
                    break;

                ans += chars[nextIdx];
                --cnt[nextIdx];
            }
            else
            {
                ans += chars[idx];
                --cnt[idx];
            }
        }

        return ans;
    }
};