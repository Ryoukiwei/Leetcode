#include <bits/stdc++.h>
using namespace std;

// dp sol:
//  dp initial: dp(n+1, INT_MAX), dp[0] = 0
//  dp[i+j*j] = min(dp[i+j*j], dp[i]+1);

class Solution
{
public:
    // Key: Lagrange's four-square theorem
    // Every natural number can be represented as a sum of four non-negative integer squares.
    // So the returned answer will only be 1, 2, 3, or 4.
    int numSquares(int n)
    {
        while (!(n % 4))
            n /= 4;

        if (n % 8 == 7)
            return 4;

        for (int i = 0; i * i <= n; i++)
        {
            int j = sqrt(n - i * i);
            if (i * i + j * j == n)
                return !(!i) + !(!j);
        }

        return 3;
    }
};