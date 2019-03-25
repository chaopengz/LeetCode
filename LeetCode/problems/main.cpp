#include "055.cpp"

int main()
{
    Solution s;
    int a[] = {2,0};
    vector<int> va(a, a + 2);
    std::cout << s.canJump(va);
}