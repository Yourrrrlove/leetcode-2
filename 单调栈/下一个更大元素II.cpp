#include <iostream>
#include <vector>
#include <stack>
using namespace std;

//取模模拟环形数组,就变成每日温度那道题了
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1); // 没找到的话为-1，找到了更新
        //找每个温度右边第一个温度大于该温度的温度，应该用单调递增栈
        stack<int> st; //递增栈（从栈顶到栈底的温度值严格递增），存放温度的下标
        st.push(0);
        for(int i = 1; i < 2 * nums.size(); ++i){
            while(!st.empty() && nums[i % nums.size()] > nums[st.top()]){
                result[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            // 如果当前温度<=栈顶温度 或 栈空了，直接入栈
            st.push(i % nums.size());
        }
        return result;
    }
};

int main(){
    vector<int> nums = {1, 2, 1};
    Solution s;
    vector<int> result = s.nextGreaterElements(nums);
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}