//
// Created by cpz on 2019-09-17.
//
#include "head.h"

class Solution
{
public:
    vector<int> pourWater(vector<int> &heights, int V, int K)
    {
        //类似于一个棒上有一点水，先向左倾斜，再向右倾斜，最后平衡到K
        for (int i = 0; i < V; ++i)
        {
            int cur = K;
            //move left
            while (cur > 0 && heights[cur] >= heights[cur - 1])
                cur--;
            //move right
            while (cur < heights.size() - 1 && heights[cur] >= heights[cur + 1])
                cur++;
            //move to K
            while (cur > K && heights[cur] >= heights[cur - 1])
                cur--;
            heights[cur]++;
        }
        return heights;
    }

};