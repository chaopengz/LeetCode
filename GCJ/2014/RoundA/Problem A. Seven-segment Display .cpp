//
// Created by laryzhang on 2018/12/11.
//
/*
 * Problem : https://code.google.com/codejam/contest/3214486/dashboard#s=p0
 * 思路：
 *     1. 先确定哪些管可能坏了
 *     2. 坏的管的组合有多少种 ===> 子集
 *     3. 因为坏的灯管不亮有两种可能，一是本来就该不亮，二是要亮的但是坏了亮不了，
 *        所以尝试每种可能坏的组合，将坏的灯管位置显示位置置为'.'号，可以同时匹配0(本来就该不亮)或者1(坏了亮不了)
 *     4. 将显示序列与倒计时序列进行匹配，如果能匹配，则可以获得下一个显示结果
 *     5. 判断下一显示结果是否唯一（用set），如果唯一就输出，不唯一就输出Error.
 */
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
    bool match(string s1, string s2)//显示数字与真实数字的匹配，'.'为通配符
    {
        int len1 = s1.size();
        int len2 = s2.size();
        if (len1 != len2)
            return false;
        for (int i = 0; i < len1; ++i)
        {
            if (s1[i] == '.')
                continue;
            else if (s1[i] != s2[i])
                return false;
        }
        return true;
    }

    bool match_str_vec(vector<string> v1, vector<string> v2)//显示序列与真实序列的匹配
    {
        int len1 = v1.size();
        int len2 = v2.size();
        if (len1 != len2)
            return false;
        for (int i = 0; i < len1; ++i)
        {
            if (!match(v1[i], v2[i]))
            {
                return false;
            }
        }
        return true;
    }

    vector<vector<int> > getAllSubsets(vector<int> set)//得到坏的管的子集，即所有可能坏的结果的组合
    {
        vector<vector<int> > subset;
        vector<int> empty;
        subset.push_back(empty);

        for (int i = 0; i < set.size(); i++)
        {
            vector<vector<int> > subsetTemp = subset;

            for (int j = 0; j < subsetTemp.size(); j++)
                subsetTemp[j].push_back(set[i]);

            for (int j = 0; j < subsetTemp.size(); j++)
                subset.push_back(subsetTemp[j]);
        }
        return subset;
    }

    vector<string> get_regular_expression(vector<string> inputs, vector<int> bad_set)//结合坏管的情况，将显示结果映射为带通配符结果
    {
        vector<string> results;

        for (auto str:inputs)
        {
            for (auto index:bad_set)
            {
                str[index] = '.';
            }
            results.push_back(str);
        }
        return results;
    }

    string get_bad_output(string input, vector<int> bad)//结合坏管情况，得到下个输出结果
    {
        string result = input;
        for (auto i:bad)
        {
            if (result[i] == '1')
                result[i] = '0';
        }
        return result;
    }

    int solve()
    {
        freopen("A-small-practice.in", "r", stdin);
        freopen("A-small-practice.txt", "w", stdout);
        int T;
        cin >> T;
        int cnt = 1;
        while (T--)
        {

            vector<string> light_nums = {"1111011", "1111111", "1110000", "1011111", "1011011", "0110011", "1111001",
                                         "1101101", "0110000", "1111110"};//9876543210
            set<int> lights = {0, 1, 2, 3, 4, 5, 6};
            set<int> goods;
            set<int> may_bads;
            vector<string> inputs;
            string input;
            int n;
            cin >> n;
            while (n--)
            {
                cin >> input;
                inputs.push_back(input);
                for (int i = 0; i < input.size(); ++i)
                {
                    if (input[i] == '1')
                    {
                        goods.insert(i);//得到好的管
                    }
                }
            }
            cout << "Case #" << cnt++ << ": ";
            std::set_difference(lights.begin(), lights.end(), goods.begin(), goods.end(),
                                std::inserter(may_bads, may_bads.end()));//做差，得到可能坏的管集合

            vector<int> bad_vec;//set to vec

            for (auto i:may_bads)
            {
                bad_vec.push_back(i);
            }

            set<string> ans;
            vector<vector<int>> bad_subsets = getAllSubsets(bad_vec);
            for (auto bad_subset:bad_subsets)//遍历每种管坏的情况
            {
                vector<string> reg_inputs = get_regular_expression(inputs, bad_subset);
                for (int start = 0; start < 10; ++start)//匹配时真实序列的起始位置
                {
                    vector<string> for_match_strings;
                    for (int i = 0; i < inputs.size(); ++i)
                    {
                        for_match_strings.push_back(light_nums[(start + i) % 10]);
                    }
                    if (match_str_vec(reg_inputs, for_match_strings))
                    {
                        string next_num = light_nums[(start + inputs.size()) % 10];
                        ans.insert(get_bad_output(next_num, bad_subset));
                    }
                }
            }

            if (ans.size() == 1)//判断下个显示是否唯一
                cout << *ans.begin() << endl;
            else
                cout << "ERROR!" << endl;
        }
        fclose(stdin);
        fclose(stdout);
    }

};

