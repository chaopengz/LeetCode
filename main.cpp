#include "328.cpp"
#include "buildTree.h"

int main()
{
    int a[] = {1,2,3,4};
    vector<int> v(a, a + 4);
    ListNode *head = new ListNode(v[0]);
    ListNode *pre = head;
    for (int i = 1; i < v.size(); ++i)
    {
        ListNode *node = new ListNode(v[i]);
        pre->next = node;
        pre = node;
    }
    Solution s;
    s.oddEvenList(head);
}
