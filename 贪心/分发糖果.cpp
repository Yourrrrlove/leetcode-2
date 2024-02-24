#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        // 从左到右 保证右边比左边分高的孩子的糖果数比左边多
        for(int i = 1; i < ratings.size(); ++i){
            if(ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
        }
        // 从右到左 保证左边比右边分高的孩子的糖果数比右边多
        for(int i = ratings.size() - 2; i >= 0; --i){
            //candies[i+1] + 1是右边孩子的糖果数 + 1
            //candies[i]是之前从左到右比较时确定的每个孩子的糖果数，它保证第i个孩子的糖果数比它左边孩子多
            //为了保证第i个小孩的糖果数量既大于左边的也大于右边的，取两者的最大值
            if(ratings[i] > ratings[i + 1]) candies[i] = max(candies[i + 1] + 1, candies[i]);
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};