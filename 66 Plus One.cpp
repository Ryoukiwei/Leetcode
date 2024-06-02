#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        reverse(digits.begin(), digits.end());

        bool flag = true;

        for (int &digit : digits)
        {
            if (digit == 9)
                digit = 0;
            else
            {
                digit++;
                flag = false;
                break;
            }
        }

        if (flag)
            digits.emplace_back(1);

        reverse(digits.begin(), digits.end());

        return digits;
    }
};
