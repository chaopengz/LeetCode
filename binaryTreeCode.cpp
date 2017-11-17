//
// Created by chaopengz on 2017/11/15.
//
#include "head.h"


int lookup(TreeNode *root, int target)
{
    //1.BaseCase empty,处理空值
    if (!root)
        return false;
    else
    {
        //2.处理节点值，如果节点值刚好是要查找的
        if (target == root->val)
            return true;
            //3.如果不是，那么递归处理子树
        else
        {
            if (target < root->val)
                return lookup(root->left, target);
            else
                return lookup(root->right, target);
        }
    }
}

TreeNode *insert(TreeNode *root, int data)
{
    //1. 树为空，直接创建并返回这个节点
    if (!root)
        return new TreeNode(data);
        //2. 处理子树
    else
    {
        if (data <= root->val)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
        //3.处理当前节点
        return root;
    }

}

TreeNode *build123()
{
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    return root;
}

int size(TreeNode *root)
{
    if (!root)
        return 0;
    else
    {
        return size(root->left) + size(root->right) + 1;
    }
}

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    else
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;

}

int minValue(TreeNode *root)
{
    TreeNode *node = root;
    while (node->left)
        node = root->left;
    return node->val;
}

void printTree(TreeNode *root)
{
    if (!root)
        return;
    printTree(root->left);
    cout << root->val;
    printTree(root->right);
}

void printPostorder(TreeNode *root)
{
    if (!root)
        return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val;
}

int hasPathSum(TreeNode *root, int sum)
{
    if (!root)
        return sum == 0;
    else
        return hasPathSum(root->left, sum - root->val)
               || hasPathSum(root->right, sum - root->val);
}

//8.path
void printPathRecur(TreeNode *root, vector<int> v)
{
    if (!root)
        return;
    //如果是叶子节点，加入vector后输出数组
    if ((!root->left) && (!root->right))
    {
        v.push_back(root->val);
        for (auto i:v)
            cout << i << " ";
        cout << endl;
    }
        //如果非叶子节点，则加入vector，然后继续遍历左右子树
    else
    {
        v.push_back(root->val);
        printPathRecur(root->left, v);
        printPathRecur(root->right, v);
    }
}

void printPath(TreeNode *root)
{
    vector<int> v;
    printPathRecur(root, v);
}


void mirror(TreeNode *root)
{
    if (!root)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
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

int sameTree(TreeNode *a, TreeNode *b)
{
    //都为空，返回真
    if (!a && !b)
        return true;
    //都不空，则比较
    if (a && b)
    {
        return a->val == b->val
               && sameTree(a->left, b->left)
               && sameTree(a->right, b->right);
    } else//一个为空一个非空，返回false
    {
        return false;
    }
}

int isBSTUtil(TreeNode *root, int min, int max)
{
    if (!root)
        return true;
    if (root->val < min || root->val > max)
        return false;
    return
            isBSTUtil(root->left, min, root->val) &&
            isBSTUtil(root->right, root->val, max);
}

int isBST(TreeNode *root)
{
    return isBSTUtil(root, INT_MIN, INT_MAX);
}
