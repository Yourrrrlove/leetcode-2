#include <iostream>
#include <queue>
using namespace std;

//使用两个队列实现栈

// class MyStack {
// public:
//     queue<int> que1, que2;
//     MyStack() {

//     }
    
//     void push(int x) {
//         que1.push(x);  //元素入栈时，直接push进que1
//     }
    
//     int pop() {
//         int size = que1.size() - 1; 
//         //要pop出栈顶元素，其实就是队尾元素出队，所以要先把que1的前size-1个元素push进que2进行备份，使que1只剩下队尾元素
//         while(size--){
//             que2.push(que1.front());
//             que1.pop();
//         }
//         int result = que1.front(); //que1的队尾元素就是栈顶元素
//         que1 = que2; //把que2赋值给que1，相当于原来的que1只删除了队尾元素
//         //清空que2
//         while(!que2.empty()) que2.pop();
//         return result;
//     }
    
//     int top() {
//         return que1.back();  //队尾元素就是栈顶元素
//     }
    
//     bool empty() {
//         return que1.empty();
//     }
// };


//使用一个队列实现栈

class MyStack {
public:
    queue<int> que;
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);  //元素入栈时，直接push进que
    }
    
    int pop() {
        int size = que.size() - 1; 
        //要pop出栈顶元素，其实就是队尾元素出队，所以要先把que的前size-1个元素按顺序push进队尾元素的后面，使que的队尾元素变成队首元素
        while(size--){
            que.push(que.front()); //将原来队尾元素前面的元素按顺序push进队尾元素的后面
            que.pop();
        }
        int result = que.front(); //que原来的队尾元素，即现在的队首元素就是栈顶元素
        que.pop(); //删除队首元素（原来的队尾元素）
        return result;
    }
    
    int top() {
        return que.back();  //队尾元素就是栈顶元素
    }
    
    bool empty() {
        return que.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */