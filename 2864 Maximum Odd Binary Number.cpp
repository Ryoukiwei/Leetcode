#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        size_t ones = count(s.begin(), s.end(), '1');
        size_t n = s.length(), zeros = n - ones;
        string ans = "1";

        if (zeros > 0)
            ans += string(zeros, '0');
        if (ones > 1)
            ans += string(ones - 1, '1');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};