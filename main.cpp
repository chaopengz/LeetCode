#include "101.cpp"
#include "buildTree.h"

int main()
{
    Solution so;
//    int a[] = {-2,2};
//    vector<int> v(a, a + 1);
    BuildTree build;
//    TreeNode *root = build.stringToTree("[1,2,2,3,4,4,3]");
    TreeNode *root = build.stringToTree("[1,2,2,null,3,null,3]");
    cout << so.isSymmetric(root);
}
