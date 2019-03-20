//
// Created by laryzhang on 2019/3/6.
//

#include "head.h"

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<std::pair<int, std::string>> m;
        m.push_back({1000, "M"});
        m.push_back({900, "CM"});
        m.push_back({500, "D"});
        m.push_back({400, "CD"});
        m.push_back({100, "C"});
        m.push_back({90, "XC"});
        m.push_back({50, "L"});
        m.push_back({40, "XL"});
        m.push_back({10, "X"});
        m.push_back({9, "IX"});
        m.push_back({5, "V"});
        m.push_back({4, "IV"});
        m.push_back({1, "I"});

        std::string ans;
        while (num != 0)
        {
            for (int i = 0; i < m.size(); ++i)
            {
                if (num >= m[i].first)
                {
                    ans += m[i].second;
                    num -= m[i].first;
                    break;
                }
            }
        }
        return ans;
    }
};