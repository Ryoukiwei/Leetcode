#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSelfCrossing(vector<int> &distance)
    {
        for (int i = 3; i < distance.size(); i++)
        {
            if (distance[i - 3] >= distance[i - 1] && distance[i] >= distance[i - 2])
                return true;

            if (i >= 4 && distance[i - 3] == distance[i - 1] && distance[i - 4] + distance[i] >= distance[i - 2])
                return true;

            if (i >= 5 && distance[i - 2] >= distance[i - 4] && distance[i - 3] >= distance[i - 1] && distance[i - 4] + distance[i] >= distance[i - 2] && distance[i - 5] + distance[i - 1] >= distance[i - 3])
                return true;
        }

        return false;
    }
};