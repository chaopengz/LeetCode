#include "head.h"
#include "494.cpp"

int main()
{
    int a[] = {1,1,1,1,1};
    vector<int> v(a, a + 5);

    Solution s;
    cout << s.findTargetSumWays(v, 3);
//    vector<int> v;
//    v.resize(10);
//    v[-1] = 0;
//    v[-1] = 3;
//    cout<<v[-1];


}
