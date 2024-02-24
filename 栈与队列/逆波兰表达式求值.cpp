#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st; //long long类型，防止溢出
        for(const auto &str : tokens){
            //如果当前元素是数字，直接入栈
            if(!(str == "+" || str == "-" || str == "*" || str == "/")) st.push(std::stoll(str)); //std::stoll()将string转换为long long类型
            else{ //如果当前元素是运算符，弹出栈顶两个元素，进行运算，将运算结果入栈
                long long x = st.top();
                st.pop();
                long long y = st.top();
                st.pop();
                long long num = 0;
                if(str == "+") num = y + x;
                if(str == "-") num = y - x;
                if(str == "*") num = y * x;
                if(str == "/") num = y / x;
                st.push(num);
            }
        }
        return (int) st.top();  //最后只剩下栈顶元素，将其强转为int类型并返回
    }
};

int main(){
    Solution sol;
    vector<string> RPN{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << sol.evalRPN(RPN) << endl;
    return 0;
}