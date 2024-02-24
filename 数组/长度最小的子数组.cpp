#include<iostream>
#include<vector>
#include <climits>
using namespace std;
//滑动窗口
class Solution{
public:
    int minSubArrayLen(int target, vector<int> &nums){
        int left = 0, sum = 0, length = INT_MAX; //left为滑动窗口的左边界，sum为滑动窗口内元素的和，length为满足窗口内元素之和>=target的最小子数组的长度（即最小的窗口长度）
        for(int right = 0; right < nums.size(); right++){ //right为滑动窗口的右边界
            sum += nums[right]; //窗口内元素之和
            while(sum >= target){ //当窗口内元素之和>=target时
                length = min(length, right - left + 1); //更新满足窗口内元素之和>=target的最小子数组的长度（即最小的窗口长度）
                sum -= nums[left++]; //将窗口左边界向右移动一位，同时窗口内元素之和减去窗口原来左边界的元素
                //如果sum减去原来左边界的值后，窗口内元素之和仍然>=target，则继续移动窗口左边界，直到窗口内元素之和<target
                //如果sum减去原来左边界的值后，窗口内元素之和<target，则跳出while循环，向右移动窗口右边界
            }
        }
        if(length == INT_MAX) return 0; //如果length没有被更新过，说明数组内所有元素加起来都<target，无法满足题意，返回0
        return length;
    }
};

int main(){
    Solution s;
    vector<int> vec{2,3,1,2,4,3};
    cout << s.minSubArrayLen(7, vec) << endl;
    return 0;
}