#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (string word : words)
        {
            bool found = isPalindrome(word);

            if (found)
                return word;
        }

        return "";
    }

private:
    bool isPalindrome(string &s)
    {
        size_t n = s.length();

        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] != s[n - i - 1])
                return false;
        }

        return true;
    }
};