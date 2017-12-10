//
// Created by cpz on 2017/12/11.
//
#include "head.h"

class Solution {
public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        int len = A.size();
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        sort(C.begin(), C.end());
        sort(D.begin(), D.end());

        vector<int>::iterator low, up;
        int ans = 0;
        int target;
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < len; ++j)
            {
                for (int k = 0; k < len; ++k)
                {
                    target = 0 - A[i] - B[j] - C[k];
                    low = lower_bound(D.begin(), D.end(), target);
                    up = upper_bound(D.begin(), D.end(), target);
                    ans += (up - low);
                }
            }
        }
        return ans;
    }
};