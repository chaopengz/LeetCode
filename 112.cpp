//
// Created by cpz on 2018/1/7.
//

#include "head.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root)
            return false;
        if ((!root->left) && (!root->right))//leaf node
            return root->val == sum;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }

};