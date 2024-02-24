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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummyhead = new ListNode(0);
        dummyhead->next = head;
        ListNode *cur = dummyhead;
        //以1->2->3->4->nullptr为例，现在为: 0->1->2->3->4->nullptr，cur指向0
        while(cur->next && cur->next->next){ //while循环中的代码每次对cur后面的3个节点进行处理，使这三个节点的中间节点指向第一个节点(cur后面的三个节点中的第一个)，左节点指向第三个节点(cur后面的三个节点中的第三个)
            ListNode *temp1 = cur->next->next->next, *temp2 = cur->next->next; //temp1暂存3, temp2暂存2
            cur->next->next->next = cur->next; //让2指向1
            cur->next->next = temp1; //让1指向3
            cur->next = temp2; //让0指向2
            //此时为: 0->2->1->3->4->nullptr
            cur = cur->next->next;  //cur后移两位，指向1，下次要对3->4->nullptr进行交换
        }
        ListNode* newHead = dummyhead->next;
        delete dummyhead;
        dummyhead = nullptr;
        return newHead;
    }
};