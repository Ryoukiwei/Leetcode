#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        return helper(n);
    }

private:
    string helper(int n)
    {
        if (n == 1)
            return "1";

        string prev = helper(n - 1);
        string ans;

        for (int i = 0; i < prev.length(); i++)
        {
            int count = 1;
            while (prev[i] == prev[i + 1])
            {
                count++;
                i++;
            }

            ans += to_string(count) + prev[i];
        }

        return ans;
    }
};