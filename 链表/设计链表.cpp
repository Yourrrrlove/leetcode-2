#include <iostream>
using namespace std;

class MyLinkedList {
public:
    //节点的结构体
    struct LinkedNode {
        int val;
        LinkedNode *next;
        LinkedNode(int x) : val(x), next(nullptr){}  //节点的构造函数
    };
    //MyLinkedList的构造函数，用来初始化类对象
    MyLinkedList(){
        size = 0;
        dummyhead = new LinkedNode(0);
    }
    int get(int index) {
        //index无效是指：index < 0 || index >= 链表长度
        if(index < 0 || index >= size) return -1;
        LinkedNode *cur = dummyhead;
        while(index--){ //链表要想访问第index个节点，需要让cur指针从头往后走index步
            cur = cur->next;
        }
        return cur->next->val; //返回第index个节点的值
    }
    
    void addAtHead(int val) {
        LinkedNode *node = new LinkedNode(val); //创建要放到头部的新节点
        node->next = dummyhead->next; //让新加到头部的节点指向原来的头节点
        dummyhead->next = node;  //让虚拟头节点指向新加到头部的节点
        size++; //链表长度加1
    }
    
    void addAtTail(int val) {
        LinkedNode *node = new LinkedNode(val); //创建要放到尾部的新节点
        LinkedNode *cur = dummyhead;
        while(cur->next != nullptr) cur = cur->next;  //将cur指针移动到最后一个节点
        cur->next = node;  //让最后一个节点指向新加到末尾的节点
        node->next = nullptr;  //再让新加到末尾的节点指向nullptr
        size++;  //链表长度加1
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0){ //如果index小于0，则在头部插入节点
            addAtHead(val);
        }
        else if(index == size){ //如果 index 等于链表的长度，则该节点将附加到链表的末尾
            addAtTail(val);
        }
        else if(index > size){
            //如果 index 大于链表长度，则不会插入节点
        }
        else{ //在链表中的第 index 个节点之前添加值为 val  的节点
            LinkedNode *node = new LinkedNode(val); //创建要插入的新节点
            LinkedNode *cur = dummyhead; //创建一个指针指向虚拟头节点
            //让cur指针指向第index个节点的前一个节点
            while(index--){
                cur = cur->next; 
            }
            node->next = cur->next; //让新节点指向第index个节点
            cur->next = node; //让第index个节点的前一个节点指向新节点
            size++; //链表长度加1
        }
    }
    
    void deleteAtIndex(int index) {
        if(index >=0 && index < size){
            LinkedNode *cur = dummyhead; //创建一个指针指向虚拟头节点
            //让cur指针指向第index个节点的前一个节点
            while(index--){
                cur = cur->next; 
            }
            LinkedNode *temp = cur->next; //创建一个指针指向第index个节点
            cur->next = temp->next; //让第index个节点的前一个节点指向第index个节点的后一个节点
            delete temp; //删除第index个节点
            size--; //链表长度减1
        }
    }
private:
    int size;
    LinkedNode *dummyhead;
};