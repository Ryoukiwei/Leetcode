#include <string>
#include <array>
using namespace std;

class Solution
{
public:
    bool checkInclusion(const string &s1, const string &s2)
    {
        const int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2)
            return false;

        array<int, 26> cnt{};
        int remaining = n1;

        for (const char c1 : s1)
        {
            ++cnt[c1 - 'a'];
        }

        for (int i = 0; i < n2; ++i)
        {
            if (--cnt[s2[i] - 'a'] >= 0)
                --remaining;

            if (i >= n1)
            {
                if (++cnt[s2[i - n1] - 'a'] > 0)
                    ++remaining;
            }

            if (!remaining)
                return true;
        }

        return false;
    }
};