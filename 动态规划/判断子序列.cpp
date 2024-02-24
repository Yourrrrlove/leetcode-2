#include <iostream>
#include <vector>
#include <string>
using namespace std;

//先求 s和t 的最长公共子序列的长度，不要求连续
//然后判断最长公共子序列的长度是否等于s的长度
//如果等于，说明s是t的子序列

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true; //空字符串是任何字符串的子序列
        // dp[i][j]表示从s[0]开始到s[i-1]结尾的子序列和从t[0]开始到t[j-1]结尾的子序列，两者最长公共子序列长度为dp[i][j]
        vector<vector<int>> dp(s.size() + 1, vector<int> (t.size() + 1, 0));
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 1; j <= t.size(); ++j){
                //这里应该比较s[i - 1]和t[j - 1]，而不是s[i]和t[j]，因为为了初始化方便我们让i, j从1开始，i-1, j-1才是从首元素开始比较
                if(s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};

int main(){
    string s = "abc", t = "ahbgdc";
    Solution s1;
    cout << s1.isSubsequence(s, t) << endl;
    return 0;
}