//
// Created by chaopengz on 2017/11/28.
//
#include "head.h"

class Solution {
public:
    void rotate(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
            return;
        int n = matrix[0].size();

        for (int i = 0; i < n / 2; ++i)
        {
            swap(matrix[i], matrix[n - i - 1]);
        }
        int k;
        for (int i = 0; i < n - 1; ++i)
        {
            k = 1;
            for (int j = i + 1; j < n; ++j)
            {
                swap(matrix[i][j],matrix[i-k][j+k]);
                k++;
            }
        }
        return;
    }
};