#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *node) : val(x), next(node){}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0, lengthB = 0;
        ListNode *curA = headA, *curB = headB;
        // 计算链表A的长度
        while(curA){
            ++lengthA;
            curA = curA->next;
        }
        // 计算链表B的长度
        while(curB){
            ++lengthB;
            curB = curB->next;
        }
        // 让curA, curB重新指向A， B两个链表的头部
        curA = headA, curB = headB;
        // 让curA指向较长的链表
        if(lengthB > lengthA){
            swap(lengthA, lengthB);  // 交换lengthA, lengthB的值
            //swap用来交换两个变量的值，而指针的值就是地址
            swap(curA, curB); // 交换curA, curB的值（即curA和curB两个链表节点的地址）
        }
        int gap = lengthA - lengthB;
        // 让curA后移到某节点，使该节点到A链表末尾的长度==B链表的长度
        while(gap--) curA = curA->next;
        //同时移动curA, curB，直到找到curA和curB相等的节点
        //链表相交指的是相交节点的指针相同，而不是节点的值相同
        while(curA && curB){
            if(curA == curB)  return curA;
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

int main(){
    int a = 1, b = 2;
    cout << "a的地址：" << &a << " a的值：" << a << " b的地址：" << &b << " b的值：" << b << endl;
    swap(a, b);
    cout << "a的地址：" << &a << " a的值：" << a << " b的地址：" << &b << " b的值：" << b << endl;
    return 0;
}