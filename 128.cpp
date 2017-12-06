//
// Created by cpz on 2017/12/6.
//
#include "head.h"

class Solution {
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (!nums.size())
            return 0;
        map<int, int> m;
        set<int> s;
        int len = 1;
        int ans = INT32_MIN;
        for (auto i:nums)
        {
            if (s.count(i))
                continue;
            s.insert(i);
            if (m.count(i - 1) && m.count(i + 1))
            {
                len = m[i - 1] + m[i + 1] + 1;
                m[i - m[i - 1]] = len;
                m[i + m[i + 1]] = len;
            } else if (m.count(i - 1))
            {
                len = m[i - 1] + 1;
                m[i - m[i - 1]] = len;
                m[i] = len;
            } else if (m.count(i + 1))
            {
                len = m[i + 1] + 1;
                m[i + m[i + 1]] = len;
                m[i] = len;
            } else
            {
                m[i] = 1;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};