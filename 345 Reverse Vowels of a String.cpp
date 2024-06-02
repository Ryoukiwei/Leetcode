#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int left = 0, right = s.size() - 1;
        string vowels = "aeiouAEIOU";

        while (left < right)
        {
            left = s.find_first_of(vowels, left);
            right = s.find_last_of(vowels, right);
            if (left < right)
                swap(s[left++], s[right--]);
        }
        return s;
    }
};