#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    //求解[start, end]范围内的房子能抢劫到的最大金额
    int solve(int start, int end, vector<int> &nums){
        vector<int> dp(nums.size(), 0); //dp[i]表示在前i个(包括i)房子中抢劫所能获得的最大金额为dp[i]
        dp[start] = nums[start];  //只有一间房，只能偷这一个
        dp[start + 1] = max(nums[start], nums[start + 1]);  //两间房的话，偷金额最大的
        for(int i = start + 2; i <= end; ++i){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]); //偷第i间房，或者不偷第i间房
        }
        return dp[end];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        //分两种情况：1.考虑偷第一间房，不考虑偷最后一间房；2.不考虑偷第一间房，考虑偷最后一间房
        return max(solve(0, nums.size() - 2, nums), solve(1, nums.size() - 1, nums));
    }
};