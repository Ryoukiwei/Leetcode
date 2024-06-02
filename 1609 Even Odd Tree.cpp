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
    bool isEvenOddTree(TreeNode *root)
    {
        int level = 0;
        queue<TreeNode *> q;

        q.push(root);
        while (!q.empty())
        {
            size_t n = q.size();
            int max = INT_MIN, min = INT_MAX;

            while (n--)
            {
                TreeNode *top = q.front();
                q.pop();

                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);

                if (!(level % 2))
                {
                    if (!(top->val % 2))
                        return false;

                    if (top->val > max)
                        max = top->val;
                    else
                        return false;
                }
                else
                {
                    if (top->val % 2)
                        return false;

                    if (top->val < min)
                        min = top->val;
                    else
                        return false;
                }
            }

            level++;
        }

        return true;
    }
};