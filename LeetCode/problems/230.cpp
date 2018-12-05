//
// Created by cpz on 2017/12/14.
//

#include "head.h"
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        kk = k;
        preOrder(root);
        return v[k-1];
    }
    void preOrder(TreeNode* root)
    {
        if(!root)
            return;
        preOrder(root->left);
        v.push_back(root->val);
        count++;
        if(count == kk)
            return;
        preOrder(root->right);
    }
    vector<int> v;
    int count = 0;
    int kk;
};