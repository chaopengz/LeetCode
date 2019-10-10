//
// Created by chaopengz on 2017/11/21.
//

#include "head.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> v;

        vector<vector<int>> ans;
        v.push_back(1);
        v.clear();
        ans.push_back(v);

        for (auto i:nums)
        {
            vector<vector<int>> pre;
            pre = ans;
            for (auto& row:pre)
            {
                vector<int> k;
                for (auto& col:row)
                {
                    k.push_back(col);
                }
                k.push_back(i);
                ans.push_back(k);
            }
        }

        return ans;
    }
};