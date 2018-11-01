//
// Created by chaopengz on 2017/10/10.
//

#include "head.h"
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        add(res,"",n,0);
        return res;
    }
    void add(vector<string> &v,string s,int l,int r)
    {
        if (!l && !r)
        {
            v.push_back(s);
            return;
        }

        if(l) add(v,s+"(",l-1,r+1);
        if(r) add(v,s+")",l,r-1);

    }
};