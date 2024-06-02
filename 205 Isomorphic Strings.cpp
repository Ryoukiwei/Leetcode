#include <bits/stdc++.h>
using namespace std;

class Solution
{
    const int SIZE = 128;

public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> mappingS(SIZE, -1), mappingT(SIZE, -1);

        for (int i = 0; i < s.length(); ++i)
        {
            if (mappingS[s[i]] != mappingT[t[i]])
                return false;

            mappingS[s[i]] = i;
            mappingT[t[i]] = i;
        }

        return true;
    }
};
