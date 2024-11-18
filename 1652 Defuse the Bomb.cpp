#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        const int n = code.size();
        vector<int> ans(n);

        if (k == 0)
            return ans;

        int sign = 1;
        if (k < 0)
        {
            k *= -1;
            sign = -1;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 1; j <= k; ++j)
            {
                ans[i] += code[(i + j * sign + n) % n];
            }
        }

        return ans;
    }
};