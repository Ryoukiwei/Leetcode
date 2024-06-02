#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int count = 0;

        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            count++;
        }

        if (left == 0)
            return 0;

        return left << count;
    }
};

// class Solution
// {
// public:
//     int rangeBitwiseAnd(int left, int right)
//     {
//         while (left < right)
//             right &= (right - 1);

//         return right;
//     }
// };