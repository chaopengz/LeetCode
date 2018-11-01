//
// Created by cpz on 2017/12/16.
//
#include "head.h"

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int ans = 0;
        while (n)
        {
            n &= (n - 1);
            ans++;
        }
        return ans;
    }
};