#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (!n)
            return 1.0;

        double sqrt = myPow(x, n / 2);

        if (!(n % 2))
            return sqrt * sqrt;

        return n > 0 ? sqrt * sqrt * x : sqrt * sqrt / x;
    }
};