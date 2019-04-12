#include "106.cpp"

int main()
{
    Solution s;
    vector<int> in = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    TreeNode *root = s.buildTree(in, postorder);
    std::cout << "hello world1";
}