#include "378.cpp"
#include "buildTree.h"

int main()
{
    Solution so;
    int a[] = {1, 5, 9};
    int b[] = {10, 11, 13};
    int c[] = {12, 13, 15};
    vector<int> v1(a, a + 3);
    vector<int> v2(b, b + 3);
    vector<int> v3(c, c + 3);
    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    so.kthSmallest(v,8);

}
