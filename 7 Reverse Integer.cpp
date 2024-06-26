#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0;

        while (x != 0)
        {
            if (abs(ans) > INT_MAX / 10)
                return 0;

            ans = ans * 10 + x % 10;
            x /= 10;
        }

        return ans;
    }
};