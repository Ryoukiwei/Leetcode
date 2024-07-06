#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int passThePillow(int n, int time)
    {
        int rounds = time / (n - 1);
        if (rounds & 1)
            return n - (time % (n - 1));
        return (time % (n - 1)) + 1;
    }
};