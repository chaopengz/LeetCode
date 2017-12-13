//
// Created by chaopengz on 2017/12/11.
//

#include "head.h"

class Solution {
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int len = s.size();
        int sum = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            if (m[s[i]] < m[s[i + 1]])
                sum -= m[s[i]];
            else
                sum += m[s[i]];
        }
        sum += m[s[len - 1]];
        return sum;
    }
};