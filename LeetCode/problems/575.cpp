//
// Created by 张潮鹏 on 2017/9/8.
//
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int> &candies) {
        sort(candies.begin(), candies.end());
        int kinds = 1;
        for (int i = 1; i < candies.size(); ++i) {
            if (candies[i] != candies[i - 1])
                kinds++;
        }
        if (kinds <= candies.size() / 2)
            return kinds;
        else
            return (int)candies.size() / 2;
    }
};