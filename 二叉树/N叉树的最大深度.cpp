#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class Node{
public:
    int val;
    vector<Node *> children;
    Node() {}
    Node(int x) : val(x) {}
    Node(int x, vector<Node *> childrenNodes) : val(x), children(childrenNodes) {}
}; 

//递归法
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int result = 0;
        //求所有子树的最大深度
        for(const auto &childNode : root->children) result = max(result, maxDepth(childNode));
        return 1 + result;
    }
};

//迭代法  层序遍历
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        queue<Node *> que;
        que.push(root);
        int result = 0;
        while(!que.empty()){
            int size = que.size();
            for(size_t i = 0; i < size; ++i){
                Node *cur = que.front();
                que.pop();
                //如果cur节点有孩子节点，将其孩子节点全部入队
                if(cur->children.size() > 0) for(const auto &childNode : cur->children) que.push(childNode);
            }
            ++result; //每遍历完一层，深度加1
        }
        return result;
    }
};