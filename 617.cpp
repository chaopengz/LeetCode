//
// Created by 张潮鹏 on 2017/9/6.
//


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) {
        if (t1 && t2) {
            TreeNode *root = new TreeNode(t1->val + t2->val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
            return root;

        } else {
            return t1 ? t1 : t2;
        }
    }
};