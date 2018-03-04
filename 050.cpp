//
// Created by cpz on 2018/3/5.
//
#include "head.h"

class Solution {
public:
    double myPow(double x, int n)
    {
        int absN = abs(n);
        double ans = powRec(x, absN);

        if (n < 0)
            return 1 / ans;
        else
            return ans;
    }

    double powRec(double x, int n)
    {
        if (!n)
            return 1.0;
        else
            return (n % 2) ? x * powRec(x * x, n / 2) : powRec(x * x, n / 2);
    }
};