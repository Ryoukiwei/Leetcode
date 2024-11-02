#include <string>
using namespace std;

class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        if (sentence.front() != sentence.back())
            return false;

        auto end = sentence.cend();
        for (auto it = sentence.begin(); it != end; ++it)
        {
            if (*it == ' ' && *(it - 1) != *(it + 1))
                return false;
        }
        return true;
    }
};