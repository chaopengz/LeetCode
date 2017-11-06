//
// Created by chaopengz on 2017/11/6.
//

#include "head.h"

class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int len = nums.size();
        map<int, int> m;
        for (int i = 0; i < len; ++i)
        {
            m[nums[i]] = 0;
        }
        for (int i = 0; i < len; ++i)
        {
            m[nums[i]]++;
        }

        vector<pair<int, int>> mapVector(m.begin(), m.end());

        sort(mapVector.begin(), mapVector.end(), cmp);

        vector<int> ans;
        for (int j = 0; j < k; ++j)
        {
            ans.push_back(mapVector[j].first);
        }

        return ans;

    }

    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }


};