#include "head.h"

using namespace std;
int main()
{
    string s = "abb";
    int dp[5][5] = {0};
    string s_ = "";
    for(int i = s.size() - 1; i >= 0; i--)
    {
        s_ += s[i];
    }
    int length = s.size();
    int longest = 0, endi = 0;

    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            if(i & j)
            {
                if(s[i] == s_[j])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                    dp[i][j] = 0;
            }
            else
            {
                if(s[i] == s_[j])
                    dp[i][j] = 1;
                else
                    dp[i][j] = 0;
            }
            if(dp[i][j] > longest && s[i - dp[i][j] + 1] == s_[j])
            {
                longest = dp[i][j];
                endi = i;
            }
        }
    }
    string result = "";
    for(int k = 0; k < longest; ++k)
    {
        result += s[endi--];
    }

    cout << "string" << endl;


    return 0;
}