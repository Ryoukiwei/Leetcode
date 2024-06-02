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
    TreeNode *invertTree(TreeNode *root)
    {
        mirror(root);
        return root;
    }

private:
    void mirror(TreeNode *root)
    {
        if (!root)
            return;

        TreeNode *const left = root->left;
        TreeNode *const right = root->right;

        root->left = invertTree(right);
        root->right = invertTree(left);
    }
};