#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        size_t n = haystack.length();
        size_t m = needle.length();

        if (m > n)
            return -1;

        for (int i = 0; i < n; i++)
        {
            string temp = haystack.substr(i, m);
            if (temp == needle)
                return i;
        }

        return -1;
    }
};

// class Solution
// {
// public:
//     int strStr(string haystack, string needle)
//     {
//         size_t n = haystack.length();
//         size_t m = needle.length();

//         if (m > n)
//             return -1;

//         if (!m)
//             return 0;

//         vector<int> lps = LPS(needle);

//         for (int i = 0, j = 0; i < n; i++)
//         {
//             if (haystack[i] == needle[j])
//             {
//                 j++;
//                 if (j == m)
//                     return i - j + 1;
//             }
//             else if (j)
//             {
//                 j = lps[j - 1];
//                 i--;
//             }
//         }

//         return -1;
//     }

// private:
//     vector<int> LPS(string p)
//     {
//         int l = p.length();
//         vector<int> lps(l, 0);

//         for (int i = 1, j = 0; i < l; i++)
//         {
//             while (j > 0 && p[i] != p[j])
//                 j = lps[j - 1];

//             if (p[i] == p[j])
//                 j++;

//             lps[i] = j;
//         }

//         return lps;
//     }
// };