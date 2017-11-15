//
// Created by chaopengz on 2017/11/15.
//

#ifndef LEETCODE_BUILDTREE_H
#define LEETCODE_BUILDTREE_H

#endif //LEETCODE_BUILDTREE_H

#include "head.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class BuildTree {
public:
    void trimLeftTrailingSpaces(string &input)
    {
        input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch)
        {
            return !isspace(ch);
        }));
    }

    void trimRightTrailingSpaces(string &input)
    {
        input.erase(find_if(input.rbegin(), input.rend(), [](int ch)
        {
            return !isspace(ch);
        }).base(), input.end());
    }

    TreeNode *stringToTreeNode(string input)
    {
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
        input = input.substr(1, input.length() - 2);
        if (!input.size())
        {
            return nullptr;
        }

        string item;
        stringstream ss;
        ss.str(input);

        getline(ss, item, ',');
        TreeNode *root = new TreeNode(stoi(item));
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);

        while (true)
        {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ','))
            {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null")
            {
                int leftNumber = stoi(item);
                node->left = new TreeNode(leftNumber);
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ','))
            {
                break;
            }

            trimLeftTrailingSpaces(item);
            if (item != "null")
            {
                int rightNumber = stoi(item);
                node->right = new TreeNode(rightNumber);
                nodeQueue.push(node->right);
            }
        }
        return root;
    }

    TreeNode *stringToTree(string str)
    {
        TreeNode *root = stringToTreeNode(str);
        return root;
    }
    void doubleTree(TreeNode *root)
    {
        if (!root)
            return;;

        doubleTree(root->left);
        doubleTree(root->right);

        TreeNode *newNode = new TreeNode(root->val);
        newNode->left = root->left;
        root->left = newNode;
    }
};

