//
// Created by cpz on 2017/12/5.
//

#include "head.h"

class Solution {
public:
    bool isBalanced(TreeNode *root)
    {
        if (!root)
            return true;
        else
        {
            return abs(heightOfTree(root->left) - heightOfTree(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }

    int heightOfTree(TreeNode *root)
    {
        if (!root)
            return 0;
        else
            return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
    }
};