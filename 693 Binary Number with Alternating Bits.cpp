#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        const int temp = n ^ (n >> 2);
        return !(temp & (temp - 1));
    }
};