#include <cstring>
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
    TreeNode *replaceValueInTree(TreeNode *root)
    {
        memset(levelSums, 0, sizeof(levelSums));
        getLevelSum(root, 0);
        root->val = 0;
        modify(root, 0);
        return root;
    }

private:
    int levelSums[100001];

    void getLevelSum(TreeNode *root, int level)
    {
        if (!root)
            return;

        levelSums[level] += root->val;
        getLevelSum(root->left, level + 1);
        getLevelSum(root->right, level + 1);
    }

    void modify(TreeNode *root, int level)
    {
        const int lVal = root->left ? root->left->val : 0;
        const int rVal = root->right ? root->right->val : 0;
        const int sibSum = lVal + rVal;
        ++level;

        if (root->left)
        {
            root->left->val = levelSums[level] - sibSum;
            modify(root->left, level);
        }
        if (root->right)
        {
            root->right->val = levelSums[level] - sibSum;
            modify(root->right, level);
        }
    }
};