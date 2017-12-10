//
// Created by cpz on 2017/12/11.
//
#include "head.h"

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int len = A.size();
//        sort(A.begin(), A.end());
//        sort(B.begin(), B.end());
//        sort(C.begin(), C.end());
//        sort(D.begin(), D.end());
        int ans = 0;
        map<int, int> m;
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