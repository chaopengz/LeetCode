//
// Created by laryzhang on 2019/1/28.
//
#include "head.h"

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> map;
        for (auto i : t) {
            map[i] += 1;
        }
        unsigned long counter = map.size();

        int len = INT32_MAX;
        int head = 0;
        int begin = 0, end = 0;
        char c;
        while (end < s.size()) {
            c = s[end];
            if (map.count(c) > 0) {
                map[c] -= 1;
                if (map[c] == 0)
                    counter--;
            }
            end++;

            while(counter==0)//meet the requirement,update begin index
            {
                c = s[begin];
                if(map.count(c)>0)
                {
                    map[c] += 1;
                    if(map[c]>0)
                        counter+=1;
                }

                if(end - begin < len)
                {
                    len = end - begin;
                    head = begin;
                }

                begin++;
            }

        }
        if (len == INT32_MAX)
            return "";
        else
            return s.substr(head,len);
    }
};