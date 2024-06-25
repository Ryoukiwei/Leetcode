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
    TreeNode *bstToGst(TreeNode *root)
    {
        int sum = 0;
        reverseInOrder(root, sum);
        return root;
    }

private:
    void reverseInOrder(TreeNode *node, int &sum)
    {
        if (!node)
            return;

        reverseInOrder(node->right, sum);

        node->val += sum;
        sum = node->val;

        reverseInOrder(node->left, sum);
    }
};