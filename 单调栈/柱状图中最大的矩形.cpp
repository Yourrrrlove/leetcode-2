#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //找每个柱子左右两边第一个高度小于该柱子的柱子，应该用单调递减栈
        stack<int> st; //递减栈（从栈顶到栈底的柱子高度严格递减），存放柱子的下标
        /*
        在heights的头尾各插入一个0，这样可以保证所有柱子都能被处理到
        原因：『代码随想录』https://www.programmercarl.com/0084.%E6%9F%B1%E7%8A%B6%E5%9B%BE%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%84%E7%9F%A9%E5%BD%A2.html#%E6%80%9D%E8%B7%AF
        */
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        st.push(0);
        int result = 0;
        for(int i = 1; i < heights.size(); ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int mid = st.top(), midHeight = heights[mid];
                st.pop();
                if(!st.empty()){
                    //左边第一个高度小于midHeight的柱子的下标和高度
                    int left = st.top(), leftHeight = heights[left];
                    //右边第一个高度小于midHeight的柱子的下标和高度
                    int right = i, rightHeight = heights[i];
                    //(left, right)开区间就是以midHeight为高的最大矩形的宽度 = right - left - 1
                    //此开区间内的柱子高度都>=midHeight
                    result = max(result, (right - left - 1) * midHeight);
                    cout << "left: " << left << "   leftHeight: " << leftHeight << "   mid: " << mid << "   midHeight: " << midHeight << "   right: " << right << "   rightHeight: " << rightHeight << "   result: " << result << endl;
                }
            }
            st.push(i);
        }
        return result;
    }
};

int main(){
    vector<int> heights = {50,70,60,70,50};
    Solution s;
    cout << s.largestRectangleArea(heights) << endl;
    return 0;
}
