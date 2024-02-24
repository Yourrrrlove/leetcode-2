#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0); //dp[i]表示以nums[i]结尾的最大连续子数组和
        dp[0] = nums[0]; //初始化 只有一个元素，和为nums[0]
        int sum = 0;
        for(int i = 1; i < nums.size(); ++i){
            //当前dp[i]可以是上一个的和 + 当前元素nums[i]；也可以舍弃上一个的和，重新从nums[i]算起
            //（如果上一个的和dp[i - 1]为负数，那就应该舍弃上一个的和，从nums[i]重新算起sum）
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            sum = max(sum, dp[i]);
        }
        return sum;
    }
};