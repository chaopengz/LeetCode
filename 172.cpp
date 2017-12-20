//
// Created by chaopengz on 2017/12/20.
//

#include "head.h"

class Solution {
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        for (int i = 5; i <= n; i += 5)
        {
            ans += count_five(i);
        }
        return ans;
    }

    int count_five(int n)
    {
        int ans = 0;
        while (n / 5 >= 1)
        {
            if (n % 5 == 0)
            {
                ans++;
                n /= 5;
            }else
            {
                break;
            }

        }
        return ans;
    }
};