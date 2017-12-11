//
// Created by chaopengz on 2017/12/11.
//

#include "head.h"

class Solution {
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, int> m;
        for (auto i:s)
        {
            m[i]++;
        }
        for (int j = 0; j < s.size(); ++j)
        {
            if (m[s[j]] == 1)
                return j;
        }
        return -1;
    }
};