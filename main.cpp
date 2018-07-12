#include "fcm.cpp"
#include "buildTree.h"

int main()
{
    Solution solution;


//    int a[] = {3, 2, 9, 1, 10, 6, 5, 7};
    int a[] = {0, 1, 2, 3, 5};
    vector<int> v(a, a + 5);
    int ans1 = solution.get_max_num(v);
    cout << ans1 << endl;


}