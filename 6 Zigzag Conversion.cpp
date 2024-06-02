#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        size_t n = s.length();
        vector<string> str(numRows, "");

        int idx = 0;
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            str[idx] += s[i];

            if (!idx)
                flag = true;
            else if (idx == numRows - 1)
                flag = false;

            if (flag)
                idx++;
            else
                idx--;
        }

        string ans;
        for (auto &c : str)
        {
            ans += c;
        }

        return ans;
    }
};

// class Solution
// {
// public:
//     string convert(string s, int numRows)
//     {
//         if (numRows == 1)
//             return s;

//         size_t n = s.length();
//         int num = 2 * (numRows - 1);
//         string ans;

//         for (int i = 0; i < numRows; i++)
//         {
//             for (int j = i; j < n; j += num)
//             {
//                 ans += s[j];
//                 int pos = j + num - 2 * i;

//                 if (i && i != numRows - 1 && pos < n)
//                     ans += s[pos];
//             }
//         }

//         return ans;
//     }
// };
