//
// Created by chaopengz on 2017/10/17.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        TreeNode *temp;
        if (root->right || root->left)
        {
            temp = root->right;
            root->right = root -> left;
            root->left = temp;
        }
        if (root->left)
        {
            invertTree(root->left);
        }
        if (root->right)
        {
            invertTree(root->right);
        }
    }
};