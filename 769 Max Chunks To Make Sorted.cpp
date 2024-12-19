#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {
        const int n = arr.size();
        int ans = 0;
        int mx = INT_MIN;

        for (int i = 0; i < n; ++i)
        {
            mx = max(mx, arr[i]);
            if (mx == i)
                ++ans;
        }

        return ans;
    }
};