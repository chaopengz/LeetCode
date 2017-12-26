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

#endif //LEETCODE_HEAD_H
