#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
完全背包问题：从0-m种物品中任选（可重复选），装满容量为 n 的背包有多少种排列方式
求排列数，只能先遍历背包，再遍历物品
*/

void solve(int n, int m){
    vector<int> dp(n + 1, 0); //dp[j]表示装满容量为j的背包有dp[j]种排列方式
    dp[0] = 1;
    for(int j = 0; j <= n; ++j){ //求排列数，只能先遍历背包，再遍历物品
        for(int i = 1; i <= m; ++i){  //1 <= m < n
            if(j >= i && dp[j] < INT_MAX - dp[j - i]) dp[j] += dp[j - i];
        }
    }
    cout << dp[n] << endl;
}

int main(){
    int n, m;
    while(cin >> n >> m) solve(n, m);
    return 0;
}