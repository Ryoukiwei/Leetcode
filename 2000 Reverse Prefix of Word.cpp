#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reversePrefix(string word, char ch)
    {
        auto it = word.begin(), wend = word.end();

        for (it; it != wend; ++it)
        {
            if (*it == ch)
            {
                reverse(word.begin(), it + 1);
                break;
            }
        }

        return word;
    }
};
