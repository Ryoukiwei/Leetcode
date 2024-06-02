#include <bits/stdc++.h>
using namespace std;

class NumberContainers
{
public:
    NumberContainers() {}

    void change(int index, int number)
    {
        auto it = idxToNum.find(index);
        if (it != idxToNum.end())
        {
            int oldNumber = it->second;
            numToIndices[oldNumber].erase(index);

            if (numToIndices[oldNumber].empty())
                numToIndices.erase(oldNumber);
        }
        idxToNum[index] = number;
        numToIndices[number].insert(index);
    }

    int find(int number)
    {
        const auto it = numToIndices.find(number);
        return (it != numToIndices.cend()) ? *(it->second.begin()) : -1;
    }

private:
    unordered_map<int, int> idxToNum;
    unordered_map<int, set<int>> numToIndices;
};