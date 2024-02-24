#include <iostream>
#include <vector>
using namespace std;

void solve(int kinds, int bagSpace){
    //kinds：物品种类 bagSpace：背包总容量
    //weight：每种物品的重量 value：每种物品的价值
    //输入
    vector<int> weight(kinds + 1, 0);
    for(int i = 0; i < kinds; ++i) cin >> weight[kinds];
    vector<int> value(kinds + 1, 0);
    for(int i = 0; i < kinds; ++i) cin >> value[kinds];
    //dp[i][j]：从种类0 - i 选物品，放入容量为j的背包 能得到的最大价值
    vector<vector<int>> dp(kinds, vector<int> (bagSpace + 1, 0));
    //初始化dp数组
    for(int j = 0; j < weight[0]; ++j) dp[0][j] = 0; //背包容量 < 第0种物品的重量，不能装入第0种物品
    for(int j = weight[0]; j <= bagSpace; ++j) dp[0][j] = value[0]; //背包容量 >= 第0种物品的重量，可以装入第0种物品
    for(int i = 0; i < kinds; ++i) dp[i][0] = 0; //背包容量为0，不能装入任何物品
    for(int i = 1; i < kinds; ++i){
        for(int j = 1; j <= bagSpace; ++j){
            if(j < weight[i]) dp[i][j] = dp[i - 1][j]; //背包容量 < 第i个物品的重量，不能装入第i个物品
            /*
            dp[i - 1][j]：不装入第i个物品
            dp[i - 1][j - weight[i]] + value[i]：装入第i个物品后的总价值
            j - weight[i]：装入第i个物品后的背包剩余容量
            */
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << dp[kinds - 1][bagSpace] << endl;
}

int main(){
    int m, n;
    while(cin >> m >> n) solve(m, n);
    return 0;
}