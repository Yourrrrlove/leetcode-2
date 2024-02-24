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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;  //fast和slow都从head开始
        while(fast && fast->next){  //如果fast->next为空，那么fast->next->next就会报错（因为nullptr->next是非法的），所以要判断fast->next是否为空
            fast = fast->next->next;  //fast一次走两步
            slow = slow->next; //slow一次走一步
            if(fast == slow){  //如果fast和slow相遇，那一定是在环内相遇
                ListNode *node1 = fast, *node2 = head;  //这时定义两个指针，node2从head开始，node1从相遇点开始，两个指针一次走一步，相遇点就是环的入口
                while(node1 != node2){  //当node1和node2相遇时，就是环的入口
                    node1 = node1->next;  //node1一次走一步
                    node2 = node2->next;  //node2一次走一步
                }
                //如果if条件成立，即有环，那么一定可以找到环的入口
                return node1;
            }
        }
        //如果if条件不成立，即无环，返回nullptr
        return nullptr;
    }
};