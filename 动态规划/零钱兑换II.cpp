#include <iostream>
#include <vector>
using namespace std;

//完全背包  装满容量为 amount 的背包有几种方法？
//2 2 1 和 2 1 2 是同一种方法，所以求的是组合数，只能先遍历物品，再遍历背包
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0); // dp[i]表示装满容量为i的背包有几种方法
        dp[0] = 1; // 背包容量=0，有1种方法，即什么都不装
        //求组合数，只能先遍历物品，再遍历背包
        for(int i = 0; i < coins.size(); ++i){
            for(int j = coins[i]; j <= amount; ++j){
                dp[j] += dp[j - coins[i]];
            }
            for(int k = 0; k <= amount; ++k) cout << dp[k] << " ";
            cout << endl;
        }

        //先遍历背包容量，再遍历物品,求的是排列数
        // for (int j = 0; j <= amount; j++) { // 遍历背包容量
        //     for (int i = 0; i < coins.size(); i++) { // 遍历物品
        //         if (j - coins[i] >= 0) dp[j] += dp[j - coins[i]];
        //     }
        //     for(int k = 0; k <= amount; ++k) cout << dp[k] << " ";
        //     cout << endl;
        // }
        return dp[amount];
    }
};

int main(){
    Solution s;
    vector<int> coins = {1, 2, 5};
    cout << s.change(5, coins) << endl;
    return 0;
}