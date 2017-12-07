#include "114.cpp"
#include "buildTree.h"

int main()
{
    Solution so;
    BuildTree B;
//    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
//    vector<int> v(a, a + 12);
    string str = "[1,2,5,3,4,null,6]";
    TreeNode *root;
    root = B.stringToTree(str);
    so.flatten(root);


}
