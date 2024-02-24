#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//多重背包问题：每种物品有number[i]个，求背包所装物品的最大价值
//转换为01背包问题，将第i种物品拆分成number[i]个01背包问题
void solve(int bagsize, int kinds){
    vector<int> weight(kinds, 0), value(kinds, 0), number(kinds, 0);
    for(int i = 0; i < kinds; ++i) cin >> weight[i];
    for(int i = 0; i < kinds; ++i) cin >> value[i];
    for(int i = 0; i < kinds; ++i) cin >> number[i];
    vector<int> dp(bagsize + 1, 0); //dp[j]表示容量为j的背包所装物品的最大价值
    for(int i = 0; i < kinds; ++i){ //遍历物品种类
        for(int j = bagsize; j >= weight[i]; --j){ ////遍历背包
            for(int k = 1; k <= number[i] && j - k * weight[i] >= 0; ++k){ //遍历第i种物品的数量
                dp[j] = max(dp[j], dp[j - k * weight[i]] + k * value[i]);
            }
        }
    }
    cout << dp[bagsize] << endl;
}

int main(){
    int bagsize, kinds;
    while(cin >> bagsize >> kinds) solve(bagsize, kinds);
    return 0;
}