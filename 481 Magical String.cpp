#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int magicalString(int n)
    {
        if (n <= 3)
            return 1;

        string str = "122";
        int i = 2;
        int ans = 1;
        bool flag = false;
        char append;

        while (str.length() <= n)
        {
            int repeat = str[i++] - '0';

            if (str.back() == '2')
            {
                append = '1';
                flag = true;
            }
            else
            {
                append = '2';
                flag = false;
            }

            while (repeat-- > 0)
            {
                str += append;

                if (flag && str.length() <= n)
                    ans++;
            }
        }

        return ans;
    }
};
