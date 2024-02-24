#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//完全背包问题：装满容量为amount的背包，最少需要多少个物品？
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[j]表示装满容量为j的背包，最少需要dp[j]个物品
        vector<int> dp(amount + 1, INT_MAX); //初始化为INT_MAX，因为要取最小值
        dp[0] = 0; //背包容量=0，需要0个物品
        //求硬币个数，与顺序无关，所以先遍历物品还是先遍历背包都可以
        for(int i = 0; i < coins.size(); ++i){
            for(int j = coins[i]; j <= amount; ++j){
                //if(dp[j - coins[i]] < INT_MAX && dp[j] > dp[j - coins[i]] + 1) dp[j] = dp[j - coins[i]] + 1;
                if(dp[j - coins[i]] == INT_MAX) continue; //下面的递推公式用到dp[j - coins[i]] + 1，防止INT_MAX + 1溢出
                //min函数里边为什么要有dp[j]？因为上一次可能已经能凑出总金额j了，先记录下来，后面可能还有凑出总金额j的情况，要进行比较，取最小的
                dp[j] = min(dp[j], dp[j - coins[i]] + 1); //更新dp[j]
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount]; //如果dp[amount]没变化，说明无法凑出总金额amount
    }
};