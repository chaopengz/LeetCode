//
// Created by laryzhang on 2018/11/8
#include "../head.h"

class Solution
{
public:

    vector<pair<char, int>> str_to_pair(string str)
    {
        vector<pair<char, int>> ans;
        int len = str.size();
        if (len == 1)
        {
            char c = str[0];
            ans.push_back(std::make_pair(c, 1));
            return ans;
        }
        str += "#";
        int cnt = 1;
        char c;
        for (int i = 1; i < len + 1; ++i)
        {
            if (str[i] == str[i - 1])
            {
                cnt++;
            } else
            {
                c = str[i - 1];
                ans.push_back(std::make_pair(c, cnt));
                cnt = 1;
            }
        }
        return ans;
    }

    bool isLongPressedName(string name, string typed)
    {
        pair<char, int> result;
        vector<pair<char, int> > name_v;
        vector<pair<char, int> > type_v;
        name_v = str_to_pair(name);
        type_v = str_to_pair(typed);

        if (name_v.size() != type_v.size())
            return false;
        int len = name_v.size();
        for (int i = 0; i < len; ++i)
        {
            pair<char, int> pair_n = name_v[i];
            pair<char, int> pair_t = type_v[i];
            if (pair_n.first == pair_t.first && pair_n.second <= pair_t.second)
                continue;
            else
                return false;
        }
        return true;
    }
};