#include <string>
using namespace std;

class Solution
{
public:
    int numTilePossibilities(string tiles)
    {
        int cnt[26] = {0};
        for (const char tile : tiles)
        {
            ++cnt[tile - 'A'];
        }
        return helper(cnt);
    }

private:
    int helper(int *cnt)
    {
        int ans = 0;

        for (int i = 0; i < 26; ++i)
        {
            int *c = &cnt[i];
            if (*c)
            {
                --*c;
                ans += helper(cnt) + 1;
                ++*c;
            }
        }

        return ans;
    }
};