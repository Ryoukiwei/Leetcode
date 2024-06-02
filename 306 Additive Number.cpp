#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAdditiveNumber(string num)
    {
        size_t n = num.length();

        for (int i = 1; i < n; i++)
        {
            string str1 = num.substr(0, i);
            if (check(str1))
                break;

            for (int j = i + 1; j < n; j++)
            {
                string str2 = num.substr(i, j - i);
                if (check(str2))
                    break;

                if (helper(num.substr(j), str1, str2))
                    return true;
            }
        }

        return false;
    }

private:
    /**
     * Function to check if there are leading zeros in the given number.
     *
     * @param num The number as a string to be checked.
     * @return `true` if there are leading zeros, `false` otherwise.
     */
    bool check(const string &num)
    {
        return (num.length() > 1 && num[0] == '0');
    }

    bool helper(const string &num, const string &num1, const string &num2)
    {
        if (check(num1) || check(num2))
            return false;

        string sum = strNumAdd(num1, num2);
        if (sum == num)
            return true;

        if (sum.length() >= num.length() || num.substr(0, sum.length()) != sum)
            return false;

        return helper(num.substr(sum.length()), num2, sum);
    }

    /**
     * Function to add two large integers represented as strings.
     *
     * @param num1 The first large integer as a string.
     * @param num2 The second large integer as a string.
     * @return The result of addition of the two input integers as a string.
     */
    string strNumAdd(const string &num1, const string &num2)
    {
        if (num1.empty())
            return num2;

        if (num2.empty())
            return num1;

        string ans;
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;

        while (i >= 0 || j >= 0)
        {
            int v1 = (i >= 0) ? (num1[i--] - '0') : 0;
            int v2 = (j >= 0) ? (num2[j--] - '0') : 0;
            int sum = v1 + v2 + carry;
            ans += (sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry)
            ans += (carry + '0');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};