#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        ans.reserve(folder.size());
        string prev = "";

        for (const string &f : folder)
        {
            if (!prev.empty() && f.find(prev + "/") == 0 && f[prev.length()] == '/')
                continue;
            ans.push_back(f);
            prev = f;
        }

        return ans;
    }
};