#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        if (x < y)
        {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        int cnt_a = 0, cnt_b = 0, ans = 0;

        for (const char c : s)
        {
            if (c == 'a')
                ++cnt_a;
            else if (c == 'b')
            {
                if (cnt_a > 0)
                {
                    --cnt_a;
                    ans += x;
                }
                else
                    ++cnt_b;
            }
            else
            {
                ans += min(cnt_a, cnt_b) * y;
                cnt_a = cnt_b = 0;
            }
        }

        ans += min(cnt_a, cnt_b) * y;

        return ans;
    }
};