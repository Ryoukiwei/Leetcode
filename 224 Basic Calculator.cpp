#include <string>
using namespace std;

class Solution
{
public:
    int calculate(string s)
    {
        auto it = s.begin();
        return helper(it, s.end());
    }

private:
    int helper(string::iterator &it, string::iterator end)
    {
        int ans = 0;
        int curr = 0, sign = 1;

        while (it != end)
        {
            switch (*it)
            {
            case ' ':
                ++it;
                break;

            case '+':
                sign = 1;
                ++it;
                break;
            case '-':
                sign = -1;
                ++it;
                break;

            case '(':
                ++it;
                ans += sign * helper(it, end);
                break;
            case ')':
                ++it;
                return ans;

            default:
                if (isdigit(*it))
                {
                    curr = *it - '0';
                    while (++it != end && isdigit(*it))
                        curr = curr * 10 + (*it - '0');
                    ans += sign * curr;
                }
                break;
            }
        }

        return ans;
    }
};