//
// Created by laryzhang on 2019/3/10.
//
#include "../head.h"

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int K)
    {
        for (int i = 0; i < K; ++i)
        {
            sort(A.begin(), A.end());
            A[0] = -A[0];
        }
        int sum = 0;
        for (int j = 0; j < A.size(); ++j)
        {
            sum += A[j];
        }
        return sum;
    }
};