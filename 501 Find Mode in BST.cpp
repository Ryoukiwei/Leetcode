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
    vector<int> findMode(TreeNode *root)
    {
        inorder(root);
        return ans;
    }

private:
    vector<int> ans;
    int max = 0, count = 0, prev = INT_MIN;

    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);

        count = (root->val == prev) ? count + 1 : 1;

        if (count > max)
        {
            ans.clear();
            max = count;
            ans.push_back(root->val);
        }

        else if (count == max)
            ans.push_back(root->val);

        prev = root->val;

        inorder(root->right);
    }
};