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
    //dp[j]：容量为j的背包 能得到的最大价值
    vector<int> dp(bagSpace + 1, 0);
    //初始化dp数组
    dp[0] = 0; //背包容量=0，不能装入任何物品
    for(int i = 0; i < kinds; ++i){
        for(int j = bagSpace; j >= weight[i]; --j){ //逆序遍历，防止重复装入第i个物品
        /*
        举一个例子：物品0的重量weight[0] = 1，价值value[0] = 15
        如果正序遍历:
        dp[1] = dp[1 - weight[0]] + value[0] = 15

        dp[2] = dp[2 - weight[0]] + value[0] = 30

        此时dp[2]就已经是30了，意味着物品0，被放入了两次，所以不能正序遍历。

        为什么倒序遍历，就可以保证物品只放入一次呢？

        倒序就是先算dp[2]

        dp[2] = dp[2 - weight[0]] + value[0] = 15 （dp数组已经都初始化为0）

        dp[1] = dp[1 - weight[0]] + value[0] = 15

        所以从后往前循环，每次取得状态不会和之前取得状态重合，这样每种物品就只取一次了。
        */
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[bagSpace] << endl;
}

int main(){
    int m, n;
    while(cin >> m >> n) solve(m, n);
    return 0;
}