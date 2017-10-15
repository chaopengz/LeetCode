//
// Created by chaopengz on 2017/10/13.
//

//#include "023.cpp"
//
//int main()
//{
//    ListNode *list,*list2,*p,*pre;
//    vector<ListNode*> v;
//    p = new ListNode(0);
//    list = p;
//    pre = p;
//    for (int i = 1; i < 5; ++i)
//    {
//        p = new ListNode(i*2);
//        pre->next = p;
//        pre = p;
//    }
//    v.push_back(list);
//
//    p = new ListNode(1);
//    list2 = p;
//    pre = p;
//    for (int i = 1; i < 5; ++i)
//    {
//        p = new ListNode(i*3);
//        pre->next = p;
//        pre = p;
//    }
//    v.push_back(list2);
//
//    Solution s;
//    s.mergeKLists(v);
//}