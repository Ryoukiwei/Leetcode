#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        long long ans = 0;
        priority_queue<int> maxHeap(nums.begin(), nums.end());

        while (k--)
        {
            const int maxVal = maxHeap.top();
            maxHeap.pop();
            ans += maxVal;
            maxHeap.push((maxVal + 2) / 3);
        }

        return ans;
    }
};