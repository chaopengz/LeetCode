//
// Created by chaopengz on 2017/12/9.
//

#include "head.h"

class Solution {
public:
    int titleToNumber(string s)
    {
        map<char, int> m;
        int len = s.size();
        for (char c = 'A'; c <= 'Z'; c++)
            m[c] = c - 'A' + 1;
        int ans = 0;
        int pw;
        for (int i = len - 1; i >= 0; --i)
        {
            pw = power(26, len - 1 - i);
            ans += m[s[i]] * pw;
        }
        return ans;
    }

    int power(int i, int n)//i^n
    {
        int ans = 1;
        for (int j = 0; j < n; ++j)
        {
            ans *= i;
        }
        return ans;
    }
};