#include "154.cpp"
#include "buildTree.h"

int main()
{
    int a[] = {1, 1, 1};
    vector<int> v(a, a + 3);
    Solution solution;
    cout << solution.findMin(v);
}
