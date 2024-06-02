#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int counter = countBalance(s, '(');
        if (counter == -1)
            return false;
        if (!counter)
            return true;

        reverse(s.begin(), s.end());
        counter = countBalance(s, ')');

        return counter >= 0;
    }

private:
    int countBalance(const string &s, char paren)
    {
        int ans = 0;

        for (const char c : s)
        {
            if (c == paren || c == '*')
                ++ans;
            else
                --ans;

            if (ans < 0)
                return -1;
        }

        return ans;
    }
};