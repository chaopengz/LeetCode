//
// Created by chaopengz on 2017/11/30.
//

#include "head.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(), candidates.end());


        for (auto i:candidates)
            m[i]++;

        combinationSum2(ans, v, target, candidates, 0);
        return ans;
    }

    void combinationSum2(vector<vector<int>> &ans, vector<int> &v, int target, vector<int> candidates, int begin)
    {
        if (!target)
        {
            ans.push_back(v);
            return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i]; i += m[candidates[i]])
        {
            for (int k = 1; k <= m[candidates[i]]; ++k)
            {
                for (int j = 1; j <= k; ++j)
                {
                    v.push_back(candidates[i]);
                }

                combinationSum2(ans, v, target - candidates[i] * k, candidates, i + m[candidates[i]]);

                for (int j = 1; j <= k; ++j)
                {
                    v.pop_back();
                }

            }
        }
    }

    map<int, int> m;
};