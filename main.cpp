#include "head.h"
#include "121.cpp"


int main()
{
    int a[] = {7, 1, 5, 3, 6, 4};
    vector<int> n(a, a + 6);
    Solution s;
    cout << s.maxProfit(n);

}

