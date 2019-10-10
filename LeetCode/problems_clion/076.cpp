//
// Created by laryzhang on 2019/1/28.
//
#include "head.h"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";
        unordered_map<char, int> m;
        for (auto i:t)
            m[i]++;
        int counter = m.size();

        int begin = 0, end = 0;
        int best_begin = -1, len = INT32_MAX;
        while (end < s.size())
        {
            char c = s[end];
            if (m.count(c) > 0)
            {
                m[c]--;
                if (m[c] == 0)
                    counter--;
            }
            end++;
            while (counter == 0)
            {
                char c = s[begin];
                if (m.count(c) > 0)
                {
                    m[c]++;
                    if (m[c] == 1)
                        counter++;
                }
                if (end - begin  < len)//begin还没++呢，所以不需要end-begin+1
                {
                    best_begin = begin;
                    len = end - begin ;
                }

                begin++;

            }
        }

        string ans = "";
        if (best_begin == -1)
            return ans;
        for (int j = 0; j < len; ++j)
        {
            ans.push_back(s[best_begin++]);
        }
        return ans;
    }
};