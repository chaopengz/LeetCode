//
// Created by chaopengz on 2017/9/26.
//

#ifndef LEETCODE_HEAD_H
#define LEETCODE_HEAD_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <sstream>
#include <map>
#include <cstdlib>
#include <cstring>
#include <list>
#include <set>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <numeric>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {};
};
class Uitl
{
public:
   ListNode* buildListNode(vector<int> vec)
   {
       if(vec.empty())
           return nullptr;
       auto firstNode = new ListNode(vec[0]);
       auto pre = firstNode;
       for (int i = 1; i < vec.size(); ++i) {
           auto node = new ListNode(vec[i]);
           pre->next = node;
           pre = node;
       }
       return firstNode;
   }
};
#endif //LEETCODE_HEAD_H
