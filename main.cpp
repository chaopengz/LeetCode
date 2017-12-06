#include "128.cpp"
//#include "buildTree.h"

int main()
{
    Solution so;
    int a[] = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};
    vector<int> v(a, a + 21);
   // sort(v.begin(),v.end());

//    int a[] = {100,4,200,1,3,2};
//    vector<int> v(a,a+6);
    cout << so.longestConsecutive(v);

}
