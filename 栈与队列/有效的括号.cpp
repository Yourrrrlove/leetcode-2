#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 == 1) return false; // 奇数个字符,肯定有一个括号匹配不上
        stack<char> st;
        for(const auto &ch : s){
            // 如果是左括号,则将其对应的右括号入栈
            if(ch == '(') st.push(')');
            else if(ch == '[') st.push(']');
            else if(ch == '{') st.push('}');
            // 如果栈为空,或者栈顶元素与当前元素不匹配,则返回false
            else if(st.empty() || st.top() != ch) return false;
            // 否则就是栈顶元素和当前元素匹配上了,弹出栈顶元素
            else st.pop();
        }
        return st.empty();
    }
};