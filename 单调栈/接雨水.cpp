#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0; //至少3个柱子才能有积水
        //找每个柱子左右两边第一个高度大于该柱子的柱子，应该用单调递增栈
        stack<int> st; //递增栈（从栈顶到栈底的柱子高度严格递增），存放柱子的下标
        st.push(0);
        int result = 0;
        for(int i = 1; i < height.size(); ++i){
            while(!st.empty() && height[i] > height[st.top()]){
                //mid这个柱子是凹槽的底部，左右两边的柱子是凹槽的两边，记录凹槽的下标和高度
                int mid = st.top(), midHeight = height[mid];
                st.pop();
                if(!st.empty()){
                    //凹槽左边柱子的下标和高度
                    int left = st.top(), leftHeight = height[left];
                    //凹槽右边柱子的下标和高度
                    int right = i, rightHeight = height[i];
                    //雨水的高度是左右两边柱子的高度的较小值减去midHeight，宽度是左右两边柱子的下标的差值-1
                    //雨水的高度和宽度相乘就是雨水的体积
                    result += (min(leftHeight, rightHeight) - midHeight) * (i - left - 1);
                    cout << "left: " << left << " leftHeight: " << leftHeight << " right: " << right << " rightHeight: " << rightHeight << " mid: " << mid << " midHeight: " << midHeight << " result: " << result << endl;
                }
            }
            // 如果当前柱子<=栈顶柱子 或 栈空了，直接入栈
            st.push(i);
        }
        return result;
    }
};

int main(){
    vector<int> height = {5,4,3,4,5};
    Solution s;
    cout << s.trap(height) << endl;
    return 0;
}