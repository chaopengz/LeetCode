//
// Created by cpz on 2018/2/12.
//
#include "head.h"

class Solution {
public:
    bool isPalindrome(int x)
    {
        int ans = 0;
        int xx = x;
        while (x)
        {
            if ((INT32_MAX - (x % 10)) / 10 < ans)
                return false;
            ans = 10 * ans + (x % 10);
            x /= 10;
        }
        return ans == xx;
    }
};