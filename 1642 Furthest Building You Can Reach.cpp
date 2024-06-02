#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        size_t n = heights.size();
        priority_queue<int> maxHeap;

        for (int i = 0; i < n - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];

            if (diff <= 0)

                continue;

            if (diff <= bricks)
            {
                bricks -= diff;
                maxHeap.push(diff);
            }
            else if (ladders > 0)
            {
                if (!maxHeap.empty())
                {
                    int top = maxHeap.top();
                    if (top > diff)
                    {
                        bricks += (top - diff);
                        maxHeap.pop();
                        maxHeap.push(diff);
                    }
                }

                ladders--;
            }
            else
                return i;
        }

        return n - 1;
    }
};