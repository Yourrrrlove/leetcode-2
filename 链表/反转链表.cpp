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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while(cur){
            ListNode *temp = cur->next; // 保存cur的下一个节点
            cur->next = pre;  // cur指向pre，实现两节点的反转
            pre = cur; //pre后移
            cur = temp; // cur后移
        }
        return pre;  //while循环结束的条件是cur为空节点，所以此时cur为nullptr，pre为反转之前的最后一个节点，也就是反转之后的头节点，所以返回pre
    }
};