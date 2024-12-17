#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        int cnt[26] = {};

        for (const char &c : s)
        {
            ++cnt[c - 'a'];
        }

        string ans;
        ans.reserve(s.length());
        int prev = -1;

        for (int i = 25; i >= 0;)
        {
            if (!cnt[i])
            {
                --i;
                continue;
            }

            if (prev == i)
            {
                int next = i - 1;
                while (next >= 0 && !cnt[next])
                    --next;

                if (next < 0)
                    break;

                ans.push_back('a' + next);
                --cnt[next];
                prev = next;
            }
            else
            {
                const int appendCnt = min(cnt[i], repeatLimit);
                ans.append(appendCnt, 'a' + i);
                cnt[i] -= appendCnt;
                prev = i;
            }
        }

        return ans;
    }
};