#include <iostream>
#include <vector>
using namespace std;

//和买卖股票Ⅱ的唯一区别在于第 13 行：卖出的时候减去一个手续费即可
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0)); //dp[i][0]表示第 i 天持有股票的最大现金，dp[i][1]表示第 i 天不持有股票的最大现金
        dp[0][0] = -prices[0], dp[0][1] = 0;  //第0天持有股票，说明在第0天买入，初始现金为0，买入股票花了prices[0]，所以dp[0][0] = 0-prices[0]；第0天不持有股票，最大现金就是初始现金0
        for(int i = 1; i < prices.size(); i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]- prices[i]); //第i天持有股票有两种可能：1.之前就持有，一直没卖出去，所以dp[i][0]和dp[i-1][0]相同；2.之前不持有，最大现金为第i-1天不持有的最大现金dp[i-1][1]（之前可能买卖过，现金可能不为0），第i天买入花费prices[i]，所以dp[i][0]=dp[i-1][1]-prices[i]
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee); //第i天不持有股票也有两种可能：1.之前就不持有，那di[i][1]=dp[i-1][1]; 2. 之前持有，第i天卖出去，则第i-1天一定持有，所以dp[i][1]=dp[i-1][0]+prices[i]
        }
        return dp[prices.size()-1][1]; //最后一天一定不持有股票
    }
};
