#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        //dp[i][j]表示以s[i - 1]为结尾的子串中包含以t[j - 1]为结尾的子串的个数
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        //初始化第一行，第一列，和dp[0][0]
        for(int i = 0; i <= s.size(); i++) dp[i][0] = 1; //任何一个字符串都包含一个空串
        for(int j = 0; j <= t.size(); j++) dp[0][j] = 0;  //空字符串包含非空串的个数为0
        dp[0][0] = 1; //空串包含一个空串
        for(int i = 1; i <= s.size(); i++){
            for(int j = 1; j <= t.size(); j++){
                //防止溢出：dp[i - 1][j - 1] < INT_MAX - dp[i - 1][j]
                if(s[i - 1] == t[j - 1] && dp[i - 1][j - 1] < INT_MAX - dp[i - 1][j]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];  //使用s[i - 1]和不使用s[i - 1]两种情况相加。1.使用s[i-1]：当前俩元素相同，所以以s[i - 1]为结尾的子串中包含以t[j - 1]为结尾的子串的个数就等于以s[i - 2]为结尾的子串中包含以t[j - 2]为结尾的子串的个数; 2.不使用s[i-1]：s[i-1]之前的子串也可能包含以t[j - 1]为结尾的子串。所以dp[i][j]=两种情况相加
                //以s = "bagg", t = "bag"为例
                //s[3] = t[2]，那s中包含t的个数就等于bag中包含ba的个数 + bag中包含bag的个数
                else dp[i][j] = dp[i - 1][j]; //若s[i - 1]不等于t[j - 1]，那就模拟删除元素s[i-1]，看以s[i - 2]为结尾的子串中包含以t[j - 1]为结尾的子串的个数
                //以s = "suvc", t = "suv"为例
                //s[3]不等于t[2]，那就模拟删除s[3]，看"suv"中包含"suv"的个数
            }
        }
        return dp[s.size()][t.size()]; //dp[s.size()][t.size()]表示s中包含t的个数
    }
};