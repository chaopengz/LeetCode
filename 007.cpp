//
// Created by cpz on 2018/1/30.
//
#include "head.h"

class Solution {
public:
    int reverse(int x)
    {
        bool nag = false;
        if (x < 0) nag = true;
        x = abs(x);
        int ans = 0;
        while (x)
        {
            if ((INT32_MAX - (x % 10)) / 10 < ans)
                return 0;
            ans = 10 * ans + (x % 10);
            x /= 10;
        }
        if (nag)
            return -ans;
        else
            return ans;
    }
};