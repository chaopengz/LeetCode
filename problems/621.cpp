//
// Created by chaopengz on 2017/11/22.
//

#include "head.h"

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        map<char, int> mp;
        int len = tasks.size();
        int maxCount=0;
        for (auto i:tasks)
        {
            mp[i]++;
            maxCount = max(maxCount, mp[i]);
        }

        int ans = (maxCount - 1) * (n + 1);
        for (auto m:mp)
        {
            if (m.second == maxCount) ans++;
        }

        return max(len, ans);

    }
};