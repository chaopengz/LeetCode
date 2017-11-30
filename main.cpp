#include "053.cpp"

int main()
{
    Solution so;
    int a[] = {-2,2};
    vector<int> v(a, a + 1);
//    int a[] = {-2,1};
//    vector<int> v(a, a + 2);
    cout << so.maxSubArray(v);
}
