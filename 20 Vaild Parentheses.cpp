#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> temp;
        unordered_map<char, char> parentheses = {{')', '('}, {']', '['}, {'}', '{'}};

        for (char c : s)
        {
            if (parentheses.count(c))
            {
                if (temp.empty() || temp.top() != parentheses[c])
                    return false;

                temp.pop();
            }
            else
                temp.push(c);
        }

        return temp.empty();
    }
};
