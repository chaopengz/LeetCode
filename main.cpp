#include "head.h"
#include "494.cpp"

int main()
{
    int a[] = {1,999};
    vector<int> v(a, a + 2);

    Solution s;
    cout << s.findTargetSumWays(v, 998);
//    vector<int> v;
//    v.resize(10);
//    v[-1] = 0;
//    v[-1] = 3;
//    cout<<v[-1];


}
