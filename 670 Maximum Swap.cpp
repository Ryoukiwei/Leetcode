#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumSwap(int num)
    {
        int digits[9];
        int n = 0, i;

        int ans = num;
        while (ans > 0)
        {
            digits[n++] = ans % 10;
            ans /= 10;
        }

        reverse(digits, digits + n);

        int last[10] = {0};
        for (i = 0; i < n; ++i)
        {
            last[digits[i]] = i;
        }

        for (i = 0; i < n; ++i)
        {
            for (int d = 9; d > digits[i]; d--)
            {
                if (last[d] > i)
                {
                    swap(digits[last[d]], digits[i]);
                    ans = 0;
                    for (i = 0; i < n; ++i)
                    {
                        ans = ans * 10 + digits[i];
                    }

                    return ans;
                }
            }
        }

        return num;
    }
};