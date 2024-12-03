#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        const int n = s.length();
        const int m = spaces.size();

        char ans[n + m];
        int i = 0, j = 0, k = 0;

        while (i < n)
        {
            if (j < m && i == spaces[j])
            {
                ans[k++] = ' ';
                ++j;
            }

            ans[k++] = s[i++];
        }

        return string(ans, n + m);
    }
};