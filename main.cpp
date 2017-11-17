#include "head.h"
#include "494.cpp"

int main()
{
    int a[] = {0,0,0,1};
    vector<int> v(a, a + 4);

    Solution s;
    cout << s.findTargetSumWays(v, 1);
//    vector<int> v;
//    v.resize(10);
//    v[-1] = 0;
//    v[-1] = 3;
//    cout<<v[-1];


}
