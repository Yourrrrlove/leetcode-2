#include <iostream>
#include <vector>

using namespace std;


/*
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int curMaxArrivePos = 0, nextMaxArrivePos = 0;
        for(int i = 0; i < nums.size(); ++i){
            // 先计算下一次能到达的最远位置
            nextMaxArrivePos = max(i + nums[i], nextMaxArrivePos);
            //如果已经走到当前能到达的最远位置，那就需要再跳一次（++result）
            if(i == curMaxArrivePos){
                ++result;
                curMaxArrivePos = nextMaxArrivePos; //跳一次后更新当前能到达的最远位置
                //如果更新后的能到达的最远位置 >= 数组的最后一个位置，直接返回跳跃次数
                if(curMaxArrivePos >= nums.size() - 1) return result;
            }
        }
        return result;
    }
};

int main(){
    vector<int> nums = {2,3,1,1,4};
    Solution s;
    cout << s.jump(nums) << endl;
    return 0;
}