//
// Created by chaopengz on 2017/11/15.
//

#include "head.h"

class Solution {
public:
    int rob(TreeNode *root)
    {
        if (!root)
            return 0;

        if (!root->left && !root->right)//leaf node
            return root->val;

        if (root->left && root->right)
            return max(rob(root->left) + rob(root->right),
                       root->val + rob(root->left->left) + rob(root->left->right) + rob(root->right->left) +
                       rob(root->right->right));
        if (root->left)
            return max(rob(root->left) + rob(root->right),
                       root->val + rob(root->left->left) + rob(root->left->right));
        else
            return max(rob(root->left) + rob(root->right),
                       root->val + rob(root->right->left) + rob(root->right->right));
    }

};