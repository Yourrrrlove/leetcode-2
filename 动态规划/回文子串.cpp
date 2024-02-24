#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() <= 1) return s.size();
        //dp[i][j]表示闭区间[i, j]的子串是否为回文串，因此 j >= i
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false)); //初始化为false
        int result = 0; //统计回文子串的个数
        for(int i = s.size() - 1; i >= 0; --i){
            for(int j = i; j < s.size(); ++j){
                if(s[i] == s[j]){
                    /*
                    情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
                    情况二：下标i 与 j相差为1，例如aa，也是回文子串
                    情况三：下标：i 与 j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，
                    我们看[i,j]区间是不是回文子串就看aba是不是回文就可以了，
                    aba的区间就是 i+1 与 j-1区间，[i,j]区间是不是回文就看[i + 1, j - 1]区间是不是回文
                    即看dp[i + 1][j - 1]是否为true。
                    */
                    if(j - i == 0){
                        ++result;
                        dp[i][j] = true; //情况一
                    }
                    else if(j - i == 1){
                        ++result;
                        dp[i][j] = true; //情况二
                    }
                    //情况三用到dp[i + 1][j - 1]来判断dp[i][j]是否为true，因此遍历顺序要从下往上，从左往右
                    else if(dp[i + 1][j - 1] == true){
                        ++result;
                        dp[i][j] = true;//情况三,也可写为dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                //else dp[i][j] = false; //这句可以不写，因为初始化为false
            }
        }
        return result;

    }
};