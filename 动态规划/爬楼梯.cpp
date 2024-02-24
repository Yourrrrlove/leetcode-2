#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int climbStairs(int n){
        vector<int> dp(n + 1, 0);
        dp[1] = 1, dp[2] = 2;
        for(int i = 3; i <= n; ++i){
            /*
            到达第i阶楼梯有两种途径：
            1. 从第i-1阶楼梯往上爬一层
            2. 从第i-2阶楼梯往上爬两层
            */
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout << s.climbStairs(10) << endl;
    return 0;
}