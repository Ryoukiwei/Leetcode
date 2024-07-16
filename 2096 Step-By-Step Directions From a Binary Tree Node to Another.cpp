#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        string start_p, dest_p;

        buildPath(root, startValue, start_p);
        buildPath(root, destValue, dest_p);

        while (!start_p.empty() && !dest_p.empty() && start_p.back() == dest_p.back())
        {
            start_p.pop_back();
            dest_p.pop_back();
        }

        reverse(dest_p.begin(), dest_p.end());

        return string(start_p.length(), 'U') + dest_p;
    }

private:
    bool buildPath(TreeNode *root, int val, string &path)
    {
        if (root->val == val)
            return true;

        if (root->left && buildPath(root->left, val, path))
            path.push_back('L');
        else if (root->right && buildPath(root->right, val, path))
            path.push_back('R');

        return !path.empty();
    }
};