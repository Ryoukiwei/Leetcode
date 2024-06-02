#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     bool isPowerOfTwo(int n)
//     {
//         return (n > 0 && !(n & (n - 1)));
//     }
// };

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (!n)
            return false;

        double temp = log2(n);
        if (floor(temp) == temp)
            return true;

        return false;
    }
};