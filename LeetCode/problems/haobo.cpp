//
// Created by cpz on 2018/1/30.
//

#include "head.h"

class Solution {
public:

    TreeNode *pre = nullptr;

    void flatten(TreeNode *root)
    {
        part(root);
    }


    void part(TreeNode *&root)
    {

        if (!root)
            return;

        part(root->right);
        part(root->left);

        root->right = pre;
        root->left = NULL;
        pre = root;//this is pre, not need to return
        // cout<<pre->val<<endl;
    }
};