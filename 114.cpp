//
// Created by chaopengz on 2017/12/7.
//

#include "head.h"

class Solution {
public:
//    void flatten(TreeNode *root)
//    {
//        vector<int> v;
//        if (!root)
//            return;
//        preTravel(root, v);
//        TreeNode *pre = root;
//        pre->left = nullptr;
//        for (int i = 1; i < v.size(); i++)
//        {
//            TreeNode *node = new TreeNode(v[i]);
//            pre->right = node;
//            pre = node;
//        }
//    }
//
//    void preTravel(TreeNode *root, vector<int> &v)
//    {
//        if (!root)
//            return;
//        v.push_back(root->val);
//        preTravel(root->left, v);
//        preTravel(root->right, v);
//    }

    void flatten(TreeNode *root)
    {
        if (!root)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = preNode;
        root->left = nullptr;
        preNode = root;

    }

    TreeNode *preNode = nullptr;
};