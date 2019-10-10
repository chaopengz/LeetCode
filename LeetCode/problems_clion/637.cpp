//
// Created by chaopengz on 2017/9/9.
//
#include <string>

using namespace std;

#include <queue>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode *root) {
        queue<TreeNode *> q;
        vector<double> res;
        q.push(root);
        double sum;
        int s;
        while (!q.empty()) {
            sum = 0;
            s = (int) q.size();
            for (int i = 0; i < s; ++i) {
                TreeNode *node = q.front();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                q.pop();
            }
            res.push_back((double) sum / s);
        }
    }
};