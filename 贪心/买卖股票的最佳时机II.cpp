#include <iostream>
#include <vector>
using namespace std;

/*
假如第 0 天买入，第 3 天卖出，那么利润为：prices[3] - prices[0]。

相当于(prices[3] - prices[2]) + (prices[2] - prices[1]) + (prices[1] - prices[0])。

此时就是把利润分解为每天为单位的维度，而不是从 0 天到第 3 天整体去考虑
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 0; i < prices.size() - 1; ++i){
            // 只要第二天的价格比第一天高，就在第二天卖出
            if(prices[i + 1] - prices[i] > 0) profit += prices[i + 1] - prices[i];
        }
        return profit;
    }
};