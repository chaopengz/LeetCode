#include "334.cpp"
#include "buildTree.h"

int main()
{
    Solution so;
    int a[] = {5, 4, 3, 2, 1};
    vector<int> v(a, a + 5);
    cout << so.increasingTriplet(v);
}
