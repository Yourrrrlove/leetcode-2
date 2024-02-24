#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<int> dp(nums.size(), 0); //dp[i]表示在前i个(包括i)房子中抢劫所能获得的最大金额为dp[i]
        //初始化dp数组
        dp[0] = nums[0];  //只有一间房，只能偷这一个
        dp[1] = max(nums[0], nums[1]);  //两间房的话，偷金额最大的
        for(int i = 2; i < nums.size(); ++i){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);  //偷第i间房，或者不偷第i间房
        }
        return dp[nums.size() - 1];
    }
};