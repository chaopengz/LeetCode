//
// Created by chaopengz on 2017/10/11.
//

#include "head.h"
class Solution {
public:
    int climbStairs(int n) {
        const int MAXN = 100000;
        int a[MAXN];
        a[1]=1;
        a[2]=2;
        for (int i = 3; i < MAXN; ++i)
        {
            a[i] = a[i-1]+a[i-2];
        }
        return a[n];
    }
};