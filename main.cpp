#include "112.cpp"
#include "buildTree.h"

int main()
{
    Solution solution;
    BuildTree buildTree;
    TreeNode *root = buildTree.stringToTree("[]");

    cout << solution.hasPathSum(root, 0);
}
