#include <vector>
using namespace std;

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        vector<int> cnt(k);

        for (int num : arr)
        {
            int i = num % k;
            if (i < 0)
                i += k;

            ++cnt[i];
        }

        if (cnt[0] & 1)
            return false;

        for (int i = 1; i <= k / 2; ++i)
        {
            if (cnt[i] != cnt[k - i])
                return false;
        }

        return true;
    }
};