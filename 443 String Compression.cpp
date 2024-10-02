#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        auto read = chars.begin(), write = chars.begin(), end = chars.end();
        while (read != end)
        {
            char curr = *read;
            int cnt = 0;
            while (read != end && *read == curr)
            {
                ++read;
                ++cnt;
            }

            *write++ = curr;
            if (cnt > 1)
            {
                int digit = 0;
                while (cnt > 0)
                {
                    ++digit;
                    *write++ = '0' + cnt % 10;
                    cnt /= 10;
                }

                reverse(write - digit, write);
            }
        }

        return write - chars.begin();
    }
};