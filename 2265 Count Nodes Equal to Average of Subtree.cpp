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
    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0;
        return countAvg(root, ans);
    }

private:
    int countAvg(TreeNode *node, int &ans)
    {
        if (!node)
            return 0;

        int leftSum = countAvg(node->left, ans);
        int rightSum = countAvg(node->right, ans);

        int temp = node->val - leftSum - rightSum;

        if (!temp)
            ans++;

        return node->val + leftSum + rightSum;
    }
};
