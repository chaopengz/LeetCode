//
// Created by chaopengz on 2017/11/30.
//

#include "head.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        combinationSum(candidates, 0, ans, v, target);
        return ans;
    }

    void combinationSum(vector<int> &candidates, int begin, vector<vector<int>> &ans, vector<int> &v, int target)
    {

        if (!target)
        {
            ans.push_back(v);
            return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i]; ++i)
        {
            v.push_back(candidates[i]);
            combinationSum(candidates, i, ans, v, target - candidates[i]);
            v.pop_back();
        }
    }

};