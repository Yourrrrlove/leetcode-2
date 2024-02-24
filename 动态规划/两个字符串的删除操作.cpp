#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        //dp[i][j]表示为了使以word1[i-1]为结尾的子串和以word2[j-1]为结尾的子串相同所需要的最小操作次数
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = 0; i <= word1.size(); i++) dp[i][0] = i; //使长度为 i 的非空字符串和空字符串相同，需要删除 i 个元素，即执行 i 次删除操作
        for(int j = 0; j <= word2.size(); j++) dp[0][j] = j; //使长度为 j 的非空字符串和空字符串相同，需要删除 j 个元素，即执行 j 次删除操作
        dp[0][0] = 0; ////使空字符串和空字符串相同，需要删除 0 个元素，即执行 0 次删除操作
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                //若word1[i - 1]和word2[j - 1]相同，则使以word1[i-1]为结尾的子串和以word2[j-1]为结尾的子串相同所需要的操作次数等于以word1[i-2]为结尾的子串和以word2[j-2]为结尾的子串相同所需要的操作次数
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                //若word1[i - 1]和word2[j - 1]不相同，有三种情况：
                //1.删除元素word1[i - 1]，算一次操作,总操作次数 = 使以word1[i-2]为结尾的子串和以word2[j-1]为结尾的子串相同所需要的最小操作次数 + 1；
                //2.删除元素word2[j - 1]，算一次操作,总操作次数 = 使以word1[i-1]为结尾的子串和以word2[j-2]为结尾的子串相同所需要的最小操作次数 + 1；
                //3.删除元素word1[i - 1]和word2[j - 1]，算两次操作,总操作次数 = 使以word1[i-2]为结尾的子串和以word2[j-2]为结尾的子串相同所需要的最小操作次数 + 2。
                //应该取三种情况操作次数的最小值
                else dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
            }
        }
        return dp[word1.size()][word2.size()]; //dp[word1.size()][word2.size()]表示使word1和word2相同的最小操作次数
    }
};