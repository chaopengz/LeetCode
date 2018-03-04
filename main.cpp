#include "050.cpp"
#include "buildTree.h"

int main()
{
    Solution solution;
    BuildTree buildTree;
    TreeNode *root = buildTree.stringToTree("[]");

    cout << solution.myPow(0.00001, 2147483647);
    cout << solution.myPow(2.10000, 3);
}
