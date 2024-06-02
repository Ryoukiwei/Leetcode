#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        size_t n = s.length();
        int left = 0, right = n - 1;
        while (left < right)
        {
            if (s[left] != s[right])
                break;
            char temp = s[left];
            while (left < n && s[left] == temp)
                left++;
            while (left < right && s[right] == temp)
                right--;
        }
        return right - left + 1;
    }
};