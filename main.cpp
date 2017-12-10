#include "171.cpp"
#include "buildTree.h"

int main()
{
    int myints[] = {10, 20, 30, 30, 20, 10, 10, 20, 7, 8};
    std::vector<int> v(myints, myints + 10);           // 10 20 30 30 20 10 10 20

    std::sort(v.begin(), v.end());                // 10 10 10 20 20 20 30 30

    std::vector<int>::iterator low, up;
    low = std::lower_bound(v.begin(), v.end(), 7); //          ^
    up = std::upper_bound(v.begin(), v.end(), 7); //                   ^
    int c = up - low;
    std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
    cout << c << endl;

    return 0;
}
