#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.size() == 0) return {};
        if(temperatures.size() == 1) return {0};
        vector<int> result(temperatures.size(), 0);
        //找每个温度右边第一个温度大于该温度的温度，应该用单调递增栈
        stack<int> st; //递增栈（从栈顶到栈底的温度值严格递增），存放温度的下标
        st.push(0); // 先把第一个温度的下标入栈
        for(int i = 1; i < temperatures.size(); ++i){
            // 如果当前温度大于栈顶温度，那么就找到了首次比栈顶温度高的温度，两者相隔天数就是当前温度的下标i减去栈顶温度的下标
            while(!st.empty() && temperatures[i] > st.top()){
                result[st.top()] = i - st.top();
                st.pop();
            }
            // 如果当前温度<=栈顶温度 或 栈空了，直接入栈
            st.push(i);
        }
    }
};

int main(){
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    Solution s;
    vector<int> result = s.dailyTemperatures(temperatures);
    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}