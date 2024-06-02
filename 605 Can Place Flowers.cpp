#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int i = 0, m = flowerbed.size();

        while (i < m && n)
        {
            if (!flowerbed[i] && !(i && flowerbed[i - 1]) && (i == m - 1 || !flowerbed[i + 1]))
            {
                flowerbed[i] = 1;
                n--;
                i += 2;
            }
            else
                i++;
        }

        return !n;
    }
};