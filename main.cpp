#include "head.h"
#include "494.cpp"

int main()
{
    int a[] = {1,2,1};
    vector<int> v(a, a + 3);

    Solution s;
    cout << s.findTargetSumWays(v, 0);


}
