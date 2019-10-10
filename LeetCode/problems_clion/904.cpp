//
// Created by laryzhang on 2019/1/28.
//
#include "head.h"

class Solution {
public:
    int totalFruit(vector<int> &tree) {
        unordered_map<int, int> map;//recode the char of window
        int begin = 0, end = 0;
        int len = 0;
        int counter = 0;
        int temp;
        while (end < tree.size()) {
            temp = tree[end];
            map[temp] += 1;
            if (map[temp] == 1)
                counter++;
            end++;

            while (counter > 2) {
                temp = tree[begin];
                map[temp] -= 1;
                if (map[temp] == 0)
                    counter--;
                begin++;
            }
            //counter <= 2
            std::cout << "window: " << begin << " " << end-1<< endl;
            len = max(len, end - begin);
        }
        return len;
    }
};
