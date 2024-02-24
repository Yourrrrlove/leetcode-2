#include <iostream>
#include <vector>
using namespace std;

//问题转化为： 集合中的元素能不能装满容量为 集合元素之和/2  的背包？

class Solution{
private:
    bool solve(const vector<int>& nums, int target){
        vector<int> dp(target + 1, 0); //dp[j] 表示： 容量为j的背包，所背的物品价值最大可以为dp[j]
        for(int i = 0; i < nums.size(); ++i){
            for(int j = target; j >= nums[i]; --j){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp[target] == target;
    }
public:
    bool canPartition(const vector<int>& nums){
        int sum = 0;
        for(auto const &num : nums) sum += num;
        if(sum % 2 == 1) return false; //和为奇数，不能分成两个和相等的子集
        sum /= 2;
        return solve(nums, sum);
    }
};

int main(){
    vector<int> nums = {1, 5, 11, 5};
    Solution s;
    cout << s.canPartition(nums) << endl;
    return 0;
}