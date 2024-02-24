#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> stk_in, stk_out;
    MyQueue() {

    }
    
    void push(int x) {
        stk_in.push(x); //元素入队时，直接push进stk_in
    }
    
    int pop() {
        if(stk_out.empty()){ //元素出队时，如果stk_out为空，就把stk_in的元素全部push进stk_out
            while(!stk_in.empty()){
                stk_out.push(stk_in.top());
                stk_in.pop();
            }
        }
        //此时stk_out的栈顶元素就是队列的队首元素，直接pop出来即可
        int result = stk_out.top();
        stk_out.pop();
        return result;
    }
    
    int peek() {
        //stk_out的栈顶元素就是队列的队首元素
        //这里this指的是MyQueue对象，pop()函数是MyQueue的成员函数
        //这里不能直接调用stk_out.top()，因为如果stk_out为空，就会发生越界，所以要先pop出stk_out的栈顶元素，再push回去
        int result = this->pop();
        stk_out.push(result); //peek()函数不改变队列的状态，所以要把上一句pop出的栈顶元素push回去
        return result;
    }
    
    bool empty() {
        return stk_in.empty() && stk_out.empty(); //只有stk_in和stk_out都为空时，队列才为空
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */