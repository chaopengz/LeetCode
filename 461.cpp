//
// Created by 张潮鹏 on 2017/9/4.
//
#include <iostream>
class Solution {
public:
    int hammingDistance(int x, int y) {
        int bitsOfA[32];
        int bitsOfB[32];
        for (int i = 0; i < 32; ++i) {
            bitsOfA[i] = 0;
            bitsOfB[i] = 0;
        }
        int j = 0;
        while (x > 0) {
            bitsOfA[j++] = x % 2;
            x = x / 2;
        }
        j = 0;
        while (y > 0) {
            bitsOfB[j++] = y % 2;
            y = y / 2;
        }
        int number = 0;

        for (int k = 0; k < 32; ++k) {
            if (bitsOfA[k] != bitsOfB[k]) {
                number++;
            }
        }
        return number;
    }
};