//
// Created by laryzhang on 2018/12/11.
//
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

    static bool comp(string &s1, string &s2) {
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

            vector<string> selected;
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
