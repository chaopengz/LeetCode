//
// Created by laryzhang on 2018/12/11.
//
/*
 * https://codejam.withgoogle.com/codejam/contest/3324486/dashboard#s=p0
 * 思路：
 *      1. N个按钮总共2^N次种可能
 *      2. 如果禁止的前缀中存在重叠，则取最短的，抛弃最长的
 *      3. 用总的可能逐个减去禁止前缀的可能种树，得到最后答案
 *
 *      c++ 判断是否Begin With:
 *      pos_str.compare(0, pre_str.length(), pre_str) == 0 //pos_str是否begin with pre_str
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:

    long long Pow(int a, int N) {
        long long ans = 1;
        while (N--)
            ans *= a;
        return ans;
    }

    static bool comp(string &s1, string &s2) {//按字符串长度排序，越长越后
        return s1.size() < s2.size();
    }

    int solve() {
        freopen("A-large-practice.in","r",stdin);
        freopen("out.txt","w",stdout);

        int T;
        cin >> T;
        int t = 1;
        while (T--) {
            int N, P;
            vector<string> strs;
            cin >> N >> P;
            while (P--) {
                string s;
                cin >> s;
                strs.push_back(s);
            }
            sort(strs.begin(), strs.end(), comp);

            vector<string> selected;//处理完原始禁止前缀重叠问题后的禁止前缀集合
            for (int i = strs.size() - 1; i > 0; --i) {
                string pos_str = strs[i];
                bool is_begin_with = false;
                for (int j = i - 1; j > -1; --j) {
                    string pre_str = strs[j];
                    if (pos_str.compare(0, pre_str.length(), pre_str) == 0) {
                        is_begin_with = true;
                        break;
                    }
                }
                if (!is_begin_with)
                    selected.push_back(pos_str);
            }
            selected.push_back(strs[0]);
            long long ans = Pow(2, N);
            for (auto str:selected) {
                ans -= Pow(2, N - str.size());
            }
            cout << "Case #" << t++ << ": " << ans << endl;
        }
        fclose(stdin);
        fclose(stdout);
    }
};
