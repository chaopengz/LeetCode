//
// Created by chaopengz on 2017/9/12.
//
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
//        vector<int> res;
//        for (int i = 0; i < nums.size() - 1; ++i) {
//            for (int j = i + 1; j < nums.size(); ++j) {
//                if (nums[i] + nums[j] == target)
//                {
//                    res.push_back(i);
//                    res.push_back(j);
//                 }
//            }
//        }
//        return res;

        vector<int> res;
        map<int, int> numToIndex;
        int findNum;
        for (int i = 0; i < nums.size(); ++i) {
            findNum = target - nums[i];
            if (numToIndex.find(findNum) != numToIndex.end()) {
                res.push_back(numToIndex[findNum]) ;
                res.push_back(i);
            }
            numToIndex[nums[i]] = i;
        }
        return res;
    }
};