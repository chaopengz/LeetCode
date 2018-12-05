//
// Created by chaopengz on 2017/11/30.
//

#include "head.h"
// 自己想的非递归版本，层序遍历，空值为-1代替
//class Solution {
//public:
//    bool isSymmetric(TreeNode *root)
//    {
//        if (!root)
//            return true;
//        queue<TreeNode *> qTree;
//        vector<int> v;
//        qTree.push(root);
//        int len;
//        TreeNode *node;
//        int count = 0;
//        while (count < qTree.size())
//        {
//            v.clear();
//            count = 0;
//            len = qTree.size();
//            for (int i = 0; i < len; ++i)
//            {
//                node = qTree.front();
//                qTree.pop();
//                if (node)
//                {
//                    v.push_back(node->val);
//                    qTree.push(node->left);
//                    qTree.push(node->right);
//                    if (!node->left) count += 1;
//                    if (!node->right) count += 1;
//                } else
//                {
//                    v.push_back(-1);
//                    qTree.push(nullptr);
//                    qTree.push(nullptr);
//                    count += 2;
//                }
//            }
//            if (isSymmetricVector(v))
//                continue;
//            else
//                return false;
//        }
//        return true;
//    }
//
//    bool isSymmetricVector(vector<int> v)
//    {
//
//        int len = v.size();
//        for (int i = 0; i < len / 2; ++i)
//        {
//            if (v[i] != v[len - i - 1])
//                return false;
//        }
//        return true;
//    }
//};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        else if (left && right)
        {
            if (left->val != right->val)
                return false;
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        } else
        {
            return false;
        }
    }
};
