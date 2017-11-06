//
// Created by chaopengz on 2017/11/1.
//

#include "head.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

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