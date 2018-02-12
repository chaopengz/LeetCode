#include "014.cpp"
#include "buildTree.h"

int main()
{
    Solution solution;
    vector<string> v;
    v.push_back("abcf");
    v.push_back("abcw");
    v.push_back("abce");
    v.push_back("");

    cout << solution.longestCommonPrefix(v);

}