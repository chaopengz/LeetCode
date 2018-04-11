#include "006.cpp"
#include "buildTree.h"

int main()
{
    Solution solution;
    BuildTree buildTree;
    TreeNode *root = buildTree.stringToTree("[]");

    string str = "ABC";
    cout << solution.convert(str, 1);
}
