#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        int m = str1.length(), n = str2.length();
        return str1 + str2 == str2 + str1 ? str1.substr(0, __gcd(m, n)) : "";
    }
};
