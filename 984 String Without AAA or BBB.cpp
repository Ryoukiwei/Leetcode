#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string strWithout3a3b(int a, int b)
    {
        if (!a)
            return string(b, 'b');
        if (!b)
            return string(a, 'a');

        if (a == b)
            return "ab" + strWithout3a3b(a - 1, b - 1);
        if (a > b)
            return "aab" + strWithout3a3b(a - 2, b - 1);

        return "bba" + strWithout3a3b(a - 1, b - 2);
    }
};