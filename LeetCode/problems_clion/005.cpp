//
// Created by chaopengz on 2017/9/20.
//
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s1) {
        int dp[1005][1005];
        string s2 = "";
        for (int l = s1.size() - 1; l >= 0; l--) {
            s2 += s1[l];
        }
        int lenS1 = s1.size(), lenS2 = s2.size();
        int longest = 0, endi;

        for (int i = 0; i < lenS1; ++i) {
            for (int j = 0; j < lenS2; ++j) {

                if (i && j) {//不在首行和首列的时候
                    if (s1[i] == s2[j]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 0;
                    }
                } else {//首行和首列初始化
                    if (s1[i] == s2[j]) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 0;
                    }

                }
                if (dp[i][j] > longest) {
                    longest = dp[i][j];
                    endi = i;
                }
            }
        }
        string res = "";
        for (int k = 0; k < longest; ++k) {
            res += s1[endi--];
        }
        return res;
    }
};