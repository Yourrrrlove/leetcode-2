#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

//回文子序列不要求连续！
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.size() <= 1) return s.size();
        //dp[i][j]表示闭区间[i, j]的子串的最长回文子序列的长度，因此 j >= i
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), 0));
        for(int i = 0; i < s.size(); ++i) dp[i][i] = 1; //i == j时为同一字符，dp[i][j] = 1
        //从递推公式可以看出，遍历顺序要从下往上，从左往右
        for(int i = s.size() - 1; i >= 0; --i){ //从下往上
            for(int j = i + 1; j < s.size(); ++j){ //从左往右
                //s[i] == s[j]，把s[i]和s[j]这俩字符加入回文子序列，长度+2
                if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2; 
                //s[i] != s[j]，s[i]和s[j]这俩字符不能同时加入回文子序列，分别加入s[i]和s[j]，取s[i + 1][j]和s[i][j - 1]的最大值
                else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][s.size() - 1];
    }
};