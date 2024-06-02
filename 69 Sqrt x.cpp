#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int l = 1, r = x;

        while (l <= r)
        {
            long mid = ((long)l + (long)r) / 2;
            long temp = mid * mid;

            if (temp == x)
                return mid;

            if (temp < x)
                l = mid + 1;
            else
                r = mid - 1;
        }

        return l - 1;
    }
};