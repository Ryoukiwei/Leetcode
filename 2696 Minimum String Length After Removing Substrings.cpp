#include <string>
using namespace std;

class Solution
{
public:
    int minLength(string s)
    {
        const int n = s.length();
        int slow = 0;

        for (int fast = 0; fast < n; ++fast)
        {
            if (slow > 0 && ((s[slow - 1] == 'A' && s[fast] == 'B') || (s[slow - 1] == 'C' && s[fast] == 'D')))
                --slow;
            else
                s[slow++] = s[fast];
        }

        return slow;
    }
};