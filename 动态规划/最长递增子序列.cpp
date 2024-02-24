#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        //dp[i]表示0-i包括i的以nums[i]结尾的最长递增子序列的长度
        vector<int> dp(nums.size(), 1); //初始化为1，因为每个元素本身就是一个长度为1的递增子序列
        int result = 0;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                //未更新的以nums[i]结尾的最长递增子序列的长度dp[i] 与 0-j包括j的以nums[j]结尾的最长递增子序列的长度dp[j] + 1 比较取最大值
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            result = max(result, dp[i]);
        }
        return result;
    }
};