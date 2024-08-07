#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumSum(int num)
    {
        array<int, 4> digits;

        for (int i = 0; i < 4; ++i)
        {
            digits[i] = num % 10;
            num /= 10;
        }

        sort(digits.begin(), digits.end());
        return (digits[0] + digits[1]) * 10 + digits[2] + digits[3];
    }
};