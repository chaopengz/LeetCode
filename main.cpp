#include "034.cpp"
#include "buildTree.h"

int main()
{
    int a[] = {2, 2};
    vector<int> v(a, a + 2);
    Solution solution;
    vector<int> ans;
    ans = solution.searchRange(v, 2);
    for (auto item:ans)
    {
        cout << item << " ";
    }
}
