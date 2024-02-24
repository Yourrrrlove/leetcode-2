#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//完全背包问题：装满容量为 n 的背包所需的最少的物品个数
//这里的物品数组nums需要自己创建，从1^2,2^2....到根号n的平方
class Solution {
public:
    int numSquares(int n) {
        //创建物品数组
        vector<int> weights;
        for(int i = 1; i * i <= n; ++i) weights.push_back(i * i);
        vector<int> dp(n + 1, INT_MAX); //dp[j]表示装满容量为j的背包所需的最少的物品个数
        dp[0] = 0; //背包容量=0，需要0个物品
        for(int i = 0; i < weights.size(); ++i){
            for(int j = weights[i]; j <= n; ++j){
                if(dp[j - weights[i]] == INT_MAX) continue; //下面的递推公式用到dp[j - weights[i]] + 1，防止INT_MAX + 1溢出
                //min函数里边为什么要有dp[j]？因为上一次可能已经能凑出n了，先记录下来，后面可能还有凑出n的情况，要进行比较，取最小的
                dp[j] = min(dp[j], dp[j - weights[i]] + 1); //更新dp[j]
            }
        }
        return dp[n];
    }
};