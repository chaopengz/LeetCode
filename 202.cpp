//
// Created by chaopengz on 2017/12/14.
//
#include "head.h"

class Solution {
public:
    bool isHappy(int n)
    {
        int sum = getSum(n);
        int count = 0;
        while (sum != 1)
        {
            count++;
            sum = getSum(sum);
            if (count > 50)
                return false;
        }
        return true;
    }

    int getSum(int n)
    {
        int sum = 0;
        while (n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
};