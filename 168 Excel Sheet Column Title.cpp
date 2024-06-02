#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        return columnNumber ? convertToTitle((columnNumber - 1) / 26) + static_cast<char>((columnNumber - 1) % 26 + 'A') : "";
    }
};