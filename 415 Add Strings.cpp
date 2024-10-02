#include <string>
using namespace std;

class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string ans;
        ans.reserve(max(num1.size(), num2.size()) + 1);
        int carry = 0;

        auto it1 = num1.end(), begin1 = num1.begin();
        auto it2 = num2.end(), begin2 = num2.begin();

        while (it1 != begin1 || it2 != begin2 || carry)
        {
            if (it1 != begin1)
                carry += *--it1 - '0';
            if (it2 != begin2)
                carry += *--it2 - '0';

            ans.push_back(carry % 10 + '0');
            carry /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};