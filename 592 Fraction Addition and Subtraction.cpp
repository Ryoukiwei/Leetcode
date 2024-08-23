#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionAddition(string expression)
    {
        istringstream iss(expression);
        char c;
        int a, b, A = 0, B = 1;

        while (iss >> a >> c >> b)
        {
            A = A * b + B * a;
            B *= b;
            const int n = abs(__gcd(A, B));
            A /= n;
            B /= n;
        }

        return to_string(A) + "/" + to_string(B);
    }
};