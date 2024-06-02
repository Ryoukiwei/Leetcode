#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long r = m_sqrt(num);
        return r * r == num;
    }

private:
    long m_sqrt(int num)
    {
        long l = 1, r = num;

        while (l < r)
        {
            const long mid = (l + r) / 2;
            if (mid < num / mid)
                l = mid + 1;
            else
                r = mid;
        }

        return l;
    }
};
