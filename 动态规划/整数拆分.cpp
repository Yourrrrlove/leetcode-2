#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0); //dp[i]：拆分数字i，可以得到的最大乘积为dp[i]
        //dp[0]和dp[1]都不初始化，因为0, 1拆分不成2个正整数
        dp[2] = 1; //2只能拆分为1*1，所以最大乘积为1
        for(int i = 3; i <= n; ++i){
            for(int j = 1; j <= i / 2; ++j){
                /*
                j*dp[i-j]：拆分成j和i-j两个数，i-j继续拆分
                j*(i-j)：拆分成j和i-j两个数，i-j不再拆分
                原来的dp[i]
                以上三者取最大值，就是dp[i]更新后的值
                */
                dp[i] = max(dp[i], max(j*dp[i-j], j*(i-j))); 
            }
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.integerBreak(10) << endl;
    return 0;
}