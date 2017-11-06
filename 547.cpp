//
// Created by chaopengz on 2017/11/6.
//
#include "head.h"

class Solution {
public:
    int findCircleNum(vector<vector<int>> &M)
    {
        if (!M.size())
            return 0;
        int n = M[0].size();
        count = n;

        id.resize(n);
        sz.resize(n);

        for (int i = 0; i < n; ++i)
        {
            id[i] = i;
            sz[i] = 1;
        }


        for (int i = 0; i < n - 1; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (M[i][j])
                {
                    Union(i, j);
                }
            }
        }
        return count;
    }

    int Find(int i)
    {
        while (i != id[i])
            i = id[i];
        return i;
    }

    void Union(int i, int j)
    {
        int p = Find(i);
        int q = Find(j);
        if (p == q)
            return;
        if (sz[p] < sz[q])
        {
            id[p] = q;
            sz[q] += sz[p];
        } else
        {
            id[q] = p;
            sz[p] += sz[q];
        }
        count--;
    }

    vector<int> id;
    vector<int> sz;
    int count;
};