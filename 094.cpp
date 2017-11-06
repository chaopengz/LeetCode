//
// Created by chaopengz on 2017/11/6.
//

#include "head.h"


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        if(!root)
            return ans;

        if (root->left)
            inorderTraversal(root->left);

        ans.push_back(root->val);

        if(root->right)
            inorderTraversal(root->right);

        return ans;
    }

    vector<int> ans;
};