//
// Created by 张潮鹏 on 2017/9/7.
//
#include <cmath>

class Solution {
public:
    int findComplement(int num) {
        int result = 0, j = 0;
        while (num > 0) {
            result += (1 - num % 2) * pow(2, j++);
            num /= 2;
        }
        return result;
    }
};