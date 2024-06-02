#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        if (s.empty())
            return 0;

        size_t n = s.length(), i = s.find_first_not_of(' ');
        int sign = 1, base = 0;

        if (i != string::npos)
        {
            if (s[i] == '-')
            {
                sign = -1;
                i++;
            }
            else if (s[i] == '+')
                i++;

            while (i < n && s[i] >= '0' && s[i] <= '9')
            {
                if (base > INT_MAX / 10 || (base == INT_MAX / 10 && s[i] - '0' > 7))
                    return (sign == 1) ? INT_MAX : INT_MIN;

                base = base * 10 + (s[i++] - '0');
            }
        }

        return sign * base;
    }
};