#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        istringstream ss(sentence);
        string word;

        int idx = 1;
        const int n = searchWord.length();

        while (ss >> word)
        {
            if (word.length() >= n && word.compare(0, n, searchWord) == 0)
                return idx;
            ++idx;
        }

        return -1;
    }
};