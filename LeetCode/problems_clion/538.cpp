//
// Created by chaopengz on 2017/11/1.
//

#include "head.h"


class Solution {
private:
    int cur_sum = 0;

    void travel(TreeNode *root)
    {
        if (!root)
            return;
        if (root->right)
            travel(root->right);
        cur_sum += root->val;
        root->val = cur_sum;
        if (root->left) travel(root->left);
    }

public:
    TreeNode *convertBST(TreeNode *root)
    {
        travel(root);
        return root;
    }
};