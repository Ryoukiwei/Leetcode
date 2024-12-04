#include <string>
using namespace std;

class Solution
{
public:
    bool canMakeSubsequence(string str1, string str2)
    {
        auto it = str2.begin(), end = str2.end();
        for (const char &c : str1)
        {
            if (c == *it || (((c - 'a' + 1) % 26) + 'a') == *it)
            {
                if (++it == end)
                    return true;
            }
        }

        return false;
    }
};