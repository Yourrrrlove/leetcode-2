#include <iostream>
#include <vector>
using namespace std;

/*
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int maxArrivePos = 0;  //能到达的最远位置
        for(int i = 0; i < nums.size(); ++i){
            //之前能到达的最远位置，与 当前位置i + 从当前位置i能向前跳的步数nums[i] 取最大值，就是现在能到达的最远位置
            maxArrivePos = max(maxArrivePos, i + nums[i]);
            // 如果现在能到达的最远位置 >= 数组的最后一个位置，说明能到达最后一个位置
            if(maxArrivePos >= nums.size() - 1) return true;
        }
        return false;
    }
};