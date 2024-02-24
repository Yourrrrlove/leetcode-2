#include <iostream>
#include <list>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode *dummyhead = new ListNode(0);  //设置虚拟头节点
        dummyhead->next = head;  //让虚拟头节点指向head节点
        ListNode *cur = dummyhead;  //设置cur指针指向虚拟头节点
        while(cur->next != nullptr){
            if(cur->next->val == val){
                ListNode *temp = cur->next;
                cur->next = temp->next;
                delete temp;
                /*
                这里删除掉temp节点后，不能写cur=cur->next，例如：[0,1,1,2],val = 1
                若此时cur节点指向0，cur->next指向第一个1，删除掉1后，cur->next指向第二个1，此时如果令cur=cur->next，那么cur指向第二个1
                而程序并未判断cur->val是否等于val，所以会跳过第二个1，导致删除不干净
                */
            }
            else cur = cur->next;
        }
        head = dummyhead->next; //虚拟头节点的下一个节点就是答案
        delete dummyhead;  //删除虚拟头节点
        return head;
    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    for(int i = 1; i < 5; i++){
        ListNode *node = new ListNode(i);
        cur->next = node;
        cur = cur->next;
    }
    cur = head;
    cout << "before remove val 1:" << endl;
    while(cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    head = s.removeElements(head, 1);
    cur = head;
    cout << "after remove val 1:" << endl;
    while(cur != nullptr){
        cout << cur->val << " ";
        cur = cur->next;
    }
    cout << endl;
    return 0;
}