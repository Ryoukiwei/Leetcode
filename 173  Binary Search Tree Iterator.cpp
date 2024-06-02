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

class BSTIterator
{
public:
    BSTIterator(TreeNode *root) { goDownLeft(root); }

    int next()
    {
        TreeNode *t = s.top();
        s.pop();
        int v = t->val;

        if (t->right)
        {
            t = t->right;
            goDownLeft(t);
        }

        return v;
    }

    bool hasNext()
    {
        return !s.empty();
    }

private:
    stack<TreeNode *> s;

    void goDownLeft(TreeNode *node)
    {
        while (node)
        {
            s.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */