//
// Created by cpz on 2017/12/11.
//
#include "head.h"

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int len = A.size();

        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                int sum = C[i] + D[j];
                m[-sum]++;
            }
        }
        for (int k = 0; k < len; ++k)
        {
            for (int i = 0; i < len; ++i)
            {
                int target = A[k] + B[i];
                ans += m[target];
            }
        }
        return ans;
    }
};