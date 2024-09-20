#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diffWaysToCompute(string expression)
    {
        return helper(expression.begin(), expression.end());
    }

private:
    vector<int> helper(string::iterator first, string::iterator second)
    {
        vector<int> ans;

        for (auto it = first; it != second; ++it)
        {
            if (*it == '+' || *it == '-' || *it == '*')
            {
                auto left = helper(first, it);
                auto right = helper(next(it), second);

                for (int l : left)
                {
                    for (int r : right)
                    {
                        switch (*it)
                        {
                        case '+':
                            ans.emplace_back(l + r);
                            break;
                        case '-':
                            ans.emplace_back(l - r);
                            break;
                        case '*':
                            ans.emplace_back(l * r);
                        default:
                            break;
                        }
                    }
                }
            }
        }

        if (ans.empty())
        {
            int num = 0;
            for (auto it = first; it != second; ++it)
            {
                num = num * 10 + (*it - '0');
            }
            ans.emplace_back(num);
        }

        return ans;
    }
};