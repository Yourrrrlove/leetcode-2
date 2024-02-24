#include <iostream>
#include <vector>
using namespace std;

// /*
// dp[i][0]——不操作所拥有的最大现金
// dp[i][1]——第一次持有所拥有的最大现金
// dp[i][2]——第一次不持有所拥有的最大现金
// dp[i][3]——第二次持有所拥有的最大现金
// dp[i][4]——第二次不持有所拥有的最大现金
// */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int> (5, 0));
        dp[0][0] = 0; // 第0天不操作，不花钱也不赚钱，所得现金为0
        dp[0][1] = -prices[0]; // 第0天第一次持有股票，要先买入股票，所得现金为负的第0天的股票价格
        dp[0][2] = 0; // 第0天第一次不持有股票，要先买入再卖出，所得现金为0
        dp[0][3] = -prices[0]; // 第0天第二次持有股票，要先买入再卖出再买入，所得现金为负的第0天的股票价格
        dp[0][4] = 0; // 第0天第二次不持有股票，要先买入再卖出再买入再卖出，所得现金为0
        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = dp[i - 1][0]; // 第i天不操作，所得现金为前一天不操作所得现金
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 第i天第一次持有股票，要么是前一天就已经持有股票，要么是前一天不操作，今天买入股票
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]); // 第i天第一次不持有股票，要么是前一天就不持有股票，要么是前一天第一次持有股票，今天卖出股票
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]); // 第i天第二次持有股票，要么是前一天就已经第二次持有股票，要么是前一天第一次不持有股票，今天买入股票
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]); // 第i天第二次不持有股票，要么是前一天就已经第二次不持有股票，要么是前一天第二次持有股票，今天卖出股票
        }
        return dp[prices.size() - 1][4]; // 最后一天第二次不持有股票所得最多现金
    }
};