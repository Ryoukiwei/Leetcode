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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }

private:
    void helper(TreeNode *node, string path, vector<string> &ans)
    {
        if (!node)
            return;

        if (!path.empty())
            path += "->";

        path += to_string(node->val);

        if (!node->left && !node->right)
        {
            ans.emplace_back(path);
            return;
        }

        helper(node->left, path, ans);
        helper(node->right, path, ans);
    }
};