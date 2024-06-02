#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSameAfterReversals(int num)
    {
        return !num || num % 10;
    }
};