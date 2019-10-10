//
// Created by chaopengz on 2017/12/20.
//

#include "head.h"

class Solution {
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        int cnt = 0;
        for (long long i = 5; n / i > 0; i *= 5)
        {
            cnt = n / i;
            ans += cnt;
        }
        return ans;
    }
};