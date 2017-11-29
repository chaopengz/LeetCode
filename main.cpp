#include "560.cpp"

int main()
{
    int a[] = {1, 1, 1};
    vector<int> v(a, a + 3);
    Solution s;
    cout << s.subarraySum(v, 2);
}
