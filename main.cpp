#include "head.h"
#include "238.cpp"

int main()
{
    Solution s;
    int a[] = {1, 2, 3};
    vector<int> v(a, a + 3);

    vector<int> ans;
    ans = s.productExceptSelf(v);
    for (auto i:ans)
        cout << i << " ";

}

