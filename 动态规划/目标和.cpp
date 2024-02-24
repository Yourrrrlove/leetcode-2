#include <iostream>
#include <vector>
using namespace std;

/*
将数组中的元素分成两组，一组是要加正号的positive，一组是要加负号的negative
positive + negative = sum;
positive - negative = target;
推导出：positive = (sum + target) / 2;
此时问题转化为：装满容量为positive的背包有几种方法？
*/
class Solution{
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto const &num : nums) sum += num;
        if(abs(sum) < abs(target)) return 0; //nums中所有元素之和小于target的绝对值，不可能得到target
        /*
        若(sum + target)为奇数，positive = (sum + target) / 2会向下取整
        例如sum+target=7，positive=7/2=3
        但我们要的是装满容量为3.5的背包有几种方法，实际的到的却是装满容量为3的背包有几种方法
        所以不可能装满容量为3.5的背包，返回0
        */
        if((sum + target) % 2 == 1) return 0;
        int positive = (sum + target) / 2;
        vector<int> dp(positive + 1, 0); //dp[j] 表示： 装满容量为j的背包有dp[j]种方法
        dp[0] = 1; //装满容量为0的背包有1种方法，就是什么都不装
        for(int i = 0; i < nums.size(); ++i){
            for(int j = positive; j >= nums[i]; --j){
                /*
                例如：要装满容量为5的背包，可以：
                先装满容量为4的背包，再装一个重量为1的物品，有dp[4]种方法
                或者先装满容量为3的背包，再装一个重量为2的物品，有dp[3]种方法
                或者先装满容量为2的背包，再装一个重量为3的物品，有dp[2]种方法
                或者先装满容量为1的背包，再装一个重量为4的物品，有dp[1]种方法
                或者先装满容量为0的背包，再装一个重量为5的物品，有dp[0]种方法
                那么凑成dp[5]有多少方法呢，就是把 所有的 dp[j - nums[i]] 累加起来。
                */
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[positive];
    }
};

int main(){
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    Solution s;
    cout << s.findTargetSumWays(nums, target) << endl;
    return 0;
}