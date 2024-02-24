#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        vector<int> dp(nums.size(), 1); //dp[i]表示以nums[i]结尾的最长连续递增子序列的长度
        int result = 0;
        for(int i = 1; i < nums.size(); ++i){
            //要求连续递增子序列，所以只需比较i和i-1位置的大小：nums[i] > nums[i - 1]
            if(nums[i] > nums[i - 1]) dp[i] = dp[i - 1] + 1;
            result = max(result, dp[i]);
        }
        return result;
    }
};