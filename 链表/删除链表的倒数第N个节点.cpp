#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode *node) : val(x), next(node){}
};
//普通方法
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int count = 0;  //记录链表中节点的个数
//         ListNode *dummyhead = new ListNode(0);  //设置一个虚拟头节点
//         dummyhead->next = head; //虚拟头节点指向head
//         ListNode *cur = dummyhead;  //cur指向虚拟头节点
//         while(cur->next){
//             count++; //每遍历一个节点，count加1
//             cur = cur->next;
//         }
//         cur = dummyhead;
//         count -= n; //要往后移动的次数为count-n
//         //后移cur，使其指向要删除节点的前一个节点
//         while(count--){
//             cur = cur->next;
//         }
//         ListNode *nodetoDelete = cur->next;
//         cur->next = nodetoDelete->next;
//         delete nodetoDelete;  //删除节点, 释放内存
//         nodetoDelete = nullptr; //将指针置空, 防止野指针
//         ListNode *result = dummyhead->next;
//         delete dummyhead; //删除虚拟头节点, 释放内存
//         dummyhead = nullptr; //将指针置空, 防止野指针
//         return result;
//     }
// };

//双指针法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*设置一个虚拟头节点, 用于处理链表只有一个节点的情况
        例如: [1], n = 1,加上dummyhead后,链表变为 0->1->nullptr，fast先走两步到nullptr
        while(fast)直接条件不成立，slow已经在要删除的节点的前一个节点了
        */
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head; //虚拟头节点指向head
        ListNode *slow = dummyhead, *fast = dummyhead;
        //fast先走n+1步
        ++n;
        while(n--) fast = fast->next;
        //fast和slow同时往后走，直到fast走到链表尾部的nullptr
        while(fast){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *nodetoDelete = slow->next;
        slow->next = nodetoDelete->next;
        delete nodetoDelete;  //删除倒数第n个节点, 释放内存
        nodetoDelete = nullptr; //将指针置空, 防止野指针
        ListNode *result = dummyhead->next;
        delete dummyhead; //删除虚拟头节点, 释放内存
        dummyhead = nullptr; //将指针置空, 防止野指针
        return result;
    }
};


int main(){
    Solution s;
    ListNode *node5 = new ListNode(5);
    node5->next = nullptr;
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);
    ListNode *cur = node1;
    cout << "Before remove: " << endl;
    while(cur){
        cout << cur->val << " ";
        cur = cur->next;
    }
    ListNode *result = s.removeNthFromEnd(node1, 2);
    cout << endl << "After remove: " << endl;
    while(result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}