#include "264.cpp"
#include "buildTree.h"

int main()
{
    Solution solution;
    BuildTree buildTree;
    TreeNode *root = buildTree.stringToTree("[]");

    cout << solution.nthUglyNumber(14);
}
