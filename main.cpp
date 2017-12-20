#include "103.cpp"
#include "buildTree.h"

int main()
{

    BuildTree build;
    TreeNode *root = build.stringToTree("[3,9,20,null,null,15,7]");
    Solution so;
    so.zigzagLevelOrder(root);
}
