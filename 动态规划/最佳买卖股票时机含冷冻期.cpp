#include <iostream>
#include <vector>
using namespace std;

/*
dp[i][0]——在第i天为持有股票的状态,所拥有的最大利润
dp[i][1]——在第i天保持不持有股票的状态，所拥有的最大利润
dp[i][2]——在第i天卖出股票，所拥有的最大利润
dp[i][3]——在第i天为冷冻期状态，所拥有的最大利润
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        //初始化第0天
        dp[0][0] = -prices[0]; //在第0天持有股票，得在第0天买入股票，花费prices[0]
        dp[0][1] = 0;  //第0天不持有股票，那就在第0天什么都不做就好了
        dp[0][2] = 0;  //在第0天卖出股票，得先在第0天买入股票，买入又卖出同一支股票，利润为0
        dp[0][3] = 0;  //在递推公式dp[1][0]中用到了dp[0][3] - prices[1]，表示在第1天要买入，那么第0天就不能买入（题目要求必须在再次购买前出售掉之前的股票），那dp[0][3]就只能为0
        for(int i = 1; i < prices.size(); i++){ //第0天的已经初始化，所以i从1开始
            //第i天持有股票，有三种情况：1.之前就已经持有；2.前一天是冷冻期，要在第i天买入；3.之前不持有股票，要在第i天买入
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));
            //第i天不持有股票，有两种情况：1.之前就不持有股票；2.第i-1天为冷冻期
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            //在第i天卖出股票，那么第i-1天一定持有股票，卖出后赚到prices[i]
            dp[i][2] = dp[i - 1][0] + prices[i];
            //第i天是冷冻期，则一定在第i-1天卖出了股票
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[prices.size() - 1][1], max(dp[prices.size() - 1][2], dp[prices.size() - 1][3])); //不持股利润一定>=持股的利润，所以不比较dp[prices.size() - 1][0]
    }
};