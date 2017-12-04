//
// Created by chaopengz on 2017/12/2.
//
#include "head.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (!matrix.size())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        bool res = false;
        for (int i = 0; i < m; ++i)
        {
            res |= binary_search(matrix[i].begin(), matrix[i].end(), target);
            if (res)
                break;
        }
        return res;
    }
};