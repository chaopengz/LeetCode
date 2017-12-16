//
// Created by cpz on 2017/12/16.
//

#include "head.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        vector<int> v;
        vector<int> prev;
        for (int i = 0; i < numRows; ++i)
        {
            v.clear();
            if (i)
                v.push_back(1);
            for (int j = 1; j < prev.size(); ++j)
            {
                v.push_back(prev[j - 1] + prev[j]);
            }
            v.push_back(1);
            ans.push_back(v);
            prev = v;
        }
        return ans;
    }
};