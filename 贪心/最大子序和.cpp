#include <iostream>
#include <vector>
#include <climits>
using namespace std;


/*
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
*/

// 暴力解法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int maxVal = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            int sum = nums[i];
            //求以i为起点的最大子序和
            for(int j = i + 1; j < nums.size(); ++j){
                maxVal = max(sum, maxVal);
                sum += nums[j];
            }
        }
        return maxVal;
    }
};

// 贪心算法
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int result = INT_MIN, sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            result = max(result, sum);
            // 如果sum小于0，那么无论下一个数是正数还是负数，只要加上sum都会变小，所以直接丢弃当前sum，从下一个数开始重新累加
            if(sum < 0) sum = 0;
        }
        return result;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
    return 0;
}