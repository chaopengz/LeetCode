//
// Created by cpz on 2018/2/5.
//

#include "head.h"

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (!s.size())
            return string();

        vector<vector<char>> ans;
        ans.resize(numRows, vector<char>());
        int len = s.size();
        int i = 0;
        int index = 0;
        bool up = true;
        while (i < len)
        {
            ans[index].push_back(s[i]);
            if (index == 0)
                up = true;
            if (index == numRows - 1)
                up = false;
            if (numRows != 1)
            {
                if (up)
                    index++;
                else
                    index--;
            }
            i++;
        }
        string res = "";
        for (auto i:ans)
        {
            for (auto j:i)
            {
                res += j;
            }
        }
        return res;
    }
};