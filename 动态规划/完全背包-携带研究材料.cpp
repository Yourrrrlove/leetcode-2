#include <iostream>
#include <vector>
using namespace std;

//一维滚动数组
void solve(int kinds, int bagSpace){
    vector<int> weight(kinds, 0), value(kinds, 0);
    for(int i = 0; i < kinds; ++i){
        cin >> weight[i] >> value[i];
    }
    vector<int> dp(bagSpace + 1, 0); // dp[i]表示背包容量为i时能获得的最大价值
    //先遍历物品，再遍历背包容量
    for(int i = 0; i < kinds; ++i){ //遍历物品
        for(int j = weight[i]; j <= bagSpace; ++j){ //遍历背包容量
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    //先遍历背包容量，再遍历物品
    // for(int j = 0; j <= bagWeight; j++) { // 遍历背包容量
    //     for(int i = 0; i < weight.size(); i++) { // 遍历物品
    //         if (j - weight[i] >= 0) dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
    //     }
    // }
    cout << dp[bagSpace] << endl;
}

// 二维dp数组
void solve2(int kinds, int bagSpace){
    vector<int> weight(kinds, 0), value(kinds, 0);
    for(int i = 0; i < kinds; ++i){
        cin >> weight[i] >> value[i];
    }    
    // dp[i][j]表示从 0 - i 种物品中挑选物品，放入容量为j的背包中能获得的最大价值
    vector<vector<int>> dp(kinds, vector<int> (bagSpace + 1, 0));
    for(int i = 0; i < kinds; ++i) dp[i][0] = 0;
    for(int j = 0; j <= bagSpace; ++j){
        if(j >= weight[0]) dp[0][j] = value[0];
    }
    //二维dp数组只能 先遍历物品，再遍历背包容量
    for(int i = 1; i < kinds; ++i){ //遍历物品
        for(int j = 1; j <= bagSpace; ++j){ //遍历背包容量
            if(j < weight[i]){
                dp[i][j] = dp[i - 1][j]; //背包容量 < 第i个物品的重量，不能装入第i个物品
            }else{
                /*
                01背包问题的状态转移方程：dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])
                完全背包问题的状态转移方程：dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i])
                因为完全背包问题中，第i种物品可以放入多次，所以状态转移方程中的第二项是dp[i][j - weight[i]]而不是dp[i - 1][j - weight[i]]
                */
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[kinds - 1][bagSpace] << endl;
}

int main(){
    int N, V;
    while(cin >> N >> V) solve(N, V);
    return 0;
}