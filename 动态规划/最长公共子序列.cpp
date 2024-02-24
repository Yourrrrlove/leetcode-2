#include <iostream>
#include <vector>
#include <string>
using namespace std;

//本题求最长 公共子序列 的长度，不要求连续
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //dp[i][j]表示从text1[0]开始到text1[i-1]结尾的子序列和从text2[0]开始到text2[j-1]结尾的子序列，两者最长公共子序列长度为dp[i][j]
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0)); //这里已经把dp[0][j]和dp[i][0]初始化为0，为什么初始化为0？
        //dp[0][j]表示两个子序列之中，有一个子序列为空（因为没有text[-1]这个元素），那最长公共子序列长度就是0，所以dp[0][j]和dp[i][0]应该初始化为0
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                //这里应该比较text1[i - 1]和text2[j - 1]，而不是text1[i]和text2[j]，因为为了初始化方便我们让i, j从1开始，i-1, j-1才是从首元素开始比较
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1; //若text1[i - 1] == text2[j - 1]，则最长公共子序列长度+1
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //若text1[i - 1] 不等于 text2[j - 1]，则看text1[0, i - 2]与text2[0, j - 1]的最长公共子序列 和 text1[0, i - 1]与text2[0, j - 2]的最长公共子序列，取最大的
                //例如：abcde和ace在第三个元素不相同了，那么最长公共子序列长度只能是前面abc和ac的最长公共子序列长度或ab和ace的最长公共子序列长度
            }
        }
        return dp[text1.size()][text2.size()]; //text1和text2的最长公共子序列长度为dp[text1.size()][text2.size()]
    }
};