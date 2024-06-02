#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long m = labs(dividend), n = labs(divisor), ans = 0;
        if (m < n)
            return 0;

        long i = n, j = 1;

        while (m >= (i << 1))
        {
            i <<= 1;
            j <<= 1;
        }
        ans += j + divide(m - i, n);

        if ((dividend < 0) != (divisor < 0))
            ans = -ans;

        return ans > INT_MAX ? INT_MAX : ans;
    }
};