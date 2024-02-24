#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
完全背包问题：装满容量为target的背包有多少种排列方式
求排列数，只能先遍历背包，再遍历物品
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0); //dp[j]表示装满容量为j的背包有dp[j]种排列方式
        dp[0] = 1; //背包容量=0，有1种排列方式，即什么都不装
        //求排列数，只能先遍历背包，再遍历物品
        for(int j = 0; j <= target; ++j){
            for(int i = 0; i < nums.size(); ++i){
                if(j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]]) dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3};
    cout << s.combinationSum4(nums, 4) << endl;
    return 0;
}