#include "572.cpp"
#include "buildTree.h"

int main()
{
    Solution so;
    BuildTree b;
    TreeNode *s = b.stringToTree("[3,4,5,1,2]");
    TreeNode *t = b.stringToTree("[4,1,2]");
    cout << so.isSubtree(s, t);
}
