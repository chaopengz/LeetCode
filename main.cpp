#include "haobo.cpp"
#include "buildTree.h"

int main()
{
    Solution solution;
    BuildTree buildTree;
    TreeNode *root = buildTree.stringToTree("[1,2,5,3,4,null,6]");
    solution.flatten(root);

}
