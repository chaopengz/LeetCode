#include "154.cpp"
#include "buildTree.h"

int main()
{
//    int a[] = {3, 4, 4, 5, 1, 1, 2, 2};
//    int a[] = {10, 1, 10, 10, 10};
    int a[] = {8, 8, 8, 8, 8, 8, 1, 8, 8};
//    int a[] = {8, 8, 1, 8, 8, 8, 8, 8, 8};
    vector<int> v(a, a + 9);


    Solution solution;
    cout << solution.findMin(v);
}
