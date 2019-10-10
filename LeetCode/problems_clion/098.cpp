//
// Created by cpz on 2019-09-23.
//
#include "head.h"

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        bool cur = true;
        if (root->left)
            cur = cur && root->val > root->left->val;
        if (root->right)
            cur = cur && root->right->val > root->val;
        return cur && isValidBST(root->left) && isValidBST(root->right);
    }
};