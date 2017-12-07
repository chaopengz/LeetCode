#include "042.cpp"
//#include "buildTree.h"

int main()
{
    Solution so;
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v(a, a + 12);
   // sort(v.begin(),v.end());

//    int a[] = {100,4,200,1,3,2};
//    vector<int> v(a,a+6);
    cout << so.trap(v);

}
