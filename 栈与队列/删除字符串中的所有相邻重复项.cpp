#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(const auto &ch : s){
            if(st.empty() || ch != st.top()) st.push(ch); //如果栈为空或者栈顶元素与当前元素不相等，则入栈
            else st.pop(); //如果栈顶元素与当前元素相等，则将栈顶元素出栈
        }
        string result;
        while(!st.empty()){
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end()); //由于栈是先进后出，所以需要将结果反转
        return result;
    }
};

int main(){
    Solution sol;
    string s = "abbaca";
    cout << sol.removeDuplicates(s) << endl;
    return 0;
}