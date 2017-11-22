#include "head.h"
#include "621.cpp"

int main()
{
//    int a[] = {1, 2, 3};
//    vector<int> v(a, a + 3);
//
//    Solution s;
//    s.subsets(v);

    char a[] = {'A', 'A', 'A', 'B', 'B', 'B'};
    vector<char> v(a, a + 6);
    Solution s;
    s.leastInterval(v,2);
}
