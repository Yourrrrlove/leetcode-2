#include <iostream>
#include <vector>
using namespace std;

/*
dp[i][0]——不操作所拥有的最大现金
dp[i][1]——第一次持有所拥有的最大现金
dp[i][2]——第一次不持有所拥有的最大现金
dp[i][3]——第二次持有所拥有的最大现金
dp[i][4]——第二次不持有所拥有的最大现金
........
dp[i][j + 1]——第1 + j/2 次持有所拥有的最大现金
dp[i][j + 2]——第1 + j/2 次不持有所拥有的最大现金

*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2*k + 1, 0));
        dp[0][0] = 0;  //第0天，不买也不卖，现金为0
        for(int i = 0; i < 2*k; i += 2){
            dp[0][i + 1] = -prices[0];  //第0天，第 1 + i/2 次买入，花费prices[0]
            dp[0][i + 2] = 0;  //第0天，第 1 + i/2 次买入又卖出，花了prices[0]又赚了prices[0]，相当于没买没卖
        }
        // dp[0][1] = -prices[0];  //第0天，第一次买入，花费prices[0]
        // dp[0][2] = 0;  //第0天，买入又卖出，现金还是0
        // dp[0][3] = -prices[0];  //第0天，买入又卖出又买入，最终相当于花了prices[0]
        // dp[0][4] = 0;  //第0天，买入又卖出又买入又卖出，现金为0
        for(int i = 1; i < prices.size(); i++){
            for(int j = 0; j < 2*k; j += 2){
                //第1 + j/2次持有：可能之前就已经持有了；或者之前没操作，在第i天买入
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j + 0] - prices[i]);
                //第1 + j/2次不持有：可能之前一直不持有第一支股票；或者之前一直持有第一支股票，现在要在第i天卖出
                dp[i][j + 2] = max(dp[i - 1][j + 2], dp[i - 1][j + 1] + prices[i]);
            }
        }
        return dp[prices.size() - 1][2*k];
    }
};