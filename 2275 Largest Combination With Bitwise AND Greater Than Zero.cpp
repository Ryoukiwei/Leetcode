#include <vector>
#include <array>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int largestCombination(vector<int> &candidates)
    {
        array<int, 24> bitCnt = {0};

        for (int candidate : candidates)
        {
            int i = 0;
            while (candidate)
            {
                bitCnt[i++] += candidate & 1;
                candidate >>= 1;
            }
        }

        return *max_element(bitCnt.begin(), bitCnt.end());
    }
};