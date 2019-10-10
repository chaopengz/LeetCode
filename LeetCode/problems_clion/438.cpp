//
// Created by laryzhang on 2019/3/26.
//
#include "head.h"

class Solution
{
public:

    vector<int> findAnagrams(string s, string p)
    {
        unordered_map<char, int> m;
        for (auto i:p)
            m[i] += 1;
        int counter = m.size();
        int len = p.size();
        int begin = 0, end = 0;
        vector<int> ans;
        char c;
        while (end < len)
        {
            c = s[end];
            if (m.count(c) > 0)
            {
                m[c] -= 1;
                if (m[c] == 0)
                    counter--;
            }
            end++;
        }
        if (counter == 0)
            ans.push_back(begin);
        end = len - 1;
        while (end < s.size())//end start from len
        {
            end++;
            c = s[end];
            if (m.count(c) > 0)
            {
                m[c] -= 1;
                if (m[c] == 0)
                    counter--;
            }
            c = s[begin];
            if (m.count(c) > 0)
            {
                m[c] += 1;
                if (m[c] == 1)
                    counter++;
            }
            begin++;
            if (counter == 0)
                ans.push_back(begin);
        }
        return ans;
    }
};