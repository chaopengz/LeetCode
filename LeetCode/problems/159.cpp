//
// Created by cpz on 2019-01-29.
//
#include "head.h"

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> map;
        int begin = 0, end = 0;
        int len = 0;
        char c;
        int counter = 0;//count none zero element of map
        while (end < s.size()) {
            c = s[end];
            map[c] += 1;
            if(map[c]==1)
                counter++;
            end++;
            while (counter > 2) {//meet the requirement, update begin index
                c = s[begin];
                map[c] -= 1;
                if (map[c] == 0)
                    counter --;
                begin++;
            }
            len = max(len, end - begin);
        }
        return len;
    }
};