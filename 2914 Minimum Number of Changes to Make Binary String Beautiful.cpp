#include <string>
using namespace std;

class Solution
{
public:
    int minChanges(string s)
    {
        int ans = 0;
        const int n = s.length();

        for (int i = 0; i < n; i += 2)
        {
            if (s[i] != s[i + 1])
                ++ans;
        }

        return ans;
    }
};