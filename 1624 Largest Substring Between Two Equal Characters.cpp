#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        size_t n = s.length();
        vector<int> firstOccur(26, -1);

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            int &d = firstOccur[s[i] - 'a'];
            if (d != -1)
                ans = max(ans, i - d - 1);
            else
                d = i;
        }

        return ans;
    }
};