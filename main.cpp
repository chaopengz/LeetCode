#include "268.cpp"
#include "buildTree.h"

int main()
{
    int a[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    vector<int> v(a, a + 9);
    Solution s;
    cout << s.missingNumber(v);
}
