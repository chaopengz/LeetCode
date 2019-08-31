//
// Created by Chaopeng Zhang on 2019-08-21.
//

#include "head.h"

class Solution {
public:
    string single_multi(char &num1, string &num2) {
        // num1 if a single number
        string ans = "";
        int jw = 0;
        for (int i = 0; i < num2.size() - 1; ++i) {
            int temp = (num1 - '0') * (num2[i] - '0');
            int gw = temp % 10 + jw;
            int sw = temp / 10;

        }
    }

    string multiply(string num1, string num2) {
        string ans = "";
        for (int i = num2.size() - 1; i >= 0; --i) {
            string temp = "";
            for (int j = num1.size() - 1; j >= 0; --j) {

            }
        }
    }
};