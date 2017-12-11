//
// Created by chaopengz on 2017/12/11.
//

#include "head.h"

class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if(s.size()!=t.size())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        else
            return false;
    }
};