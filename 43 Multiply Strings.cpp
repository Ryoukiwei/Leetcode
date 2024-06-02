#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        const int len1 = num1.length(), len2 = num2.length();
        const int len = len1 + len2;
        vector<int> result(len);

        for (int i = len1 - 1; i >= 0; --i)
        {
            for (int j = len2 - 1; j >= 0; --j)
            {
                const int mult = (num1[i] - '0') * (num2[j] - '0');
                const int sum = mult + result[i + j + 1];
                result[i + j] += sum / 10;
                result[i + j + 1] = sum % 10;
            }
        }

        int idx = 0;
        while (idx < len && !result[idx])
            ++idx;

        if (idx == len)
            return "0";

        string ans;
        for (idx; idx < len; ++idx)
        {
            ans.push_back(result[idx] + '0');
        }
        return ans;
    }
};