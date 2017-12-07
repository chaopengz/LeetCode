//
// Created by chaopengz on 2017/12/7.
//

#include "head.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        string old;
        vector<vector<string>> ans;

        bool Find;
        for (auto str:strs)
        {
            Find = false;
            old = str;
            sort(str.begin(), str.end());

            for (int i = 0; i < ans.size(); ++i)
            {
                if (ans[i][0] == str)
                {
                    ans[i].push_back(old);
                    Find = true;
                    break;
                }
            }
            if (!Find)
            {
                vector<string> v;
                v.push_back(str);
                v.push_back(old);
                ans.push_back(v);
            }
        }
        return ans;
    }
};