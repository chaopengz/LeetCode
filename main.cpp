#include "head.h"
#include "312.cpp"

int main()
{
    int a[] = {3, 1, 5, 8};
    vector<int> v(a, a + 4);

    Solution s;
    cout << s.maxCoins(v);


}
