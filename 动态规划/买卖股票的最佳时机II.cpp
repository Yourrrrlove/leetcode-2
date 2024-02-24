#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        dp[i][0]：表示第i天持有股票所得最多现金
        dp[i][1]：表示第i天不持有股票所得最多现金
        */
        if(prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int> (2, 0));
        dp[0][0] = -prices[0]; // 第0天持有股票，要先买入股票，所得现金为负的第0天的股票价格
        dp[0][1] = 0; // 第0天不持有股票，所得现金为0
        for(int i = 1; i < prices.size(); ++i){
            // 第i天持有股票，要么是前一天就已经持有股票，要么是前一天不持有股票，今天买入股票
            // 由于可以买卖多次，所以前一天不持有股票，今天买入股票 这种情况的最多现金是dp[i - 1][1] - prices[i]，其中dp[i - 1][1]是之前买卖得到的利润
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            // 第i天不持有股票，要么是前一天就不持有股票，要么是前一天持有股票，今天卖出股票
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1]; // 最后一天不持有股票所得最多现金一定大于持有股票所得最多现金
    }
};