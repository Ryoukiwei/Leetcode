#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     bool isPowerOfFour(int n)
//     {
//         return n > 0 && !(n & (n - 1)) && ((n & 0x55555555) == n);
//     }
// };

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        if (n > 0)
        {
            if (floor(log(n) / log(4)) == ceil(log(n) / log(4)))
                return true;
        }
        return false;
    }
};
