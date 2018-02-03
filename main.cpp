//#include "114.cpp"
//#include "buildTree.h"
//
//int main()
//{
//    Solution solution;
//    BuildTree buildTree;
//    TreeNode *root = buildTree.stringToTree("[1,2,5,3,4,null,6]");
//    solution.flatten(root);
//
//}
#include<iostream>
using namespace std;

class A
{
public:
    void foo()
    {
        printf("1\n");
    }
    virtual void fun()
    {
        printf("2\n");
    }
};
class B : public A
{
public:
    void foo()
    {
        printf("3\n");
    }
    void fun()
    {
        printf("4\n");
    }
};

int main(void)
{
    A a;
    B b;
    A *p = &a;
    p->foo();
    p->fun();
    p = &b;
    p->foo();
    p->fun();
    return 0;
}