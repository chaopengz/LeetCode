#include "108.cpp"
#include "buildTree.h"

int main()
{
    int a[] = {-10, -3, 0, 5, 9};
    vector<int> v(a, a + 5);
    Solution s;
    s.sortedArrayToBST(v);
}
