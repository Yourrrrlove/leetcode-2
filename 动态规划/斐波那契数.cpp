#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int fib(int n){
        if(n <= 1) return n;
        vector<int> dp(2, 0); //只需要维护两个元素
        dp[0] = 0, dp[1] = 1; //初始化F(0)， F(1)
        for(int i = 2; i <= n; ++i){
            int temp = dp[1]; //temp存放F(1)
            dp[1] = dp[0] + temp; //dp[1]存放F(0) + F(1)
            dp[0] = temp;  //dp[0]存放F(1),相当于前移
        }
        return dp[1];
    }
};

int main(){
    Solution s;
    cout << s.fib(10) << endl;
    return 0;
}