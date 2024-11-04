#include <string>
using namespace std;

class Solution
{
public:
    string compressedString(string word)
    {
        string comp;
        auto it = word.begin();
        auto end = word.end();

        while (it != end)
        {
            char curr = *it;
            int cnt = 0;
            while (it != end && curr == *it && cnt < 9)
            {
                ++cnt;
                ++it;
            }

            comp += (cnt + '0');
            comp += curr;
        }

        return comp;
    }
};