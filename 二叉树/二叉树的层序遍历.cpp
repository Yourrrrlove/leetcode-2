#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//二叉树节点的定义
struct TreeNode{
    int val;  //节点值
    TreeNode *left, *right; //指向左右孩子节点的指针
    //构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode *> que; //层序遍历，每一层从左到右遍历，访问完一个节点就将该节点从队头出队，同时把该节点的左右孩子(即下一层的节点)加入队尾
        que.push(root); //第一层(根节点)入队
        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size(); //当前层的节点个数
            vector<int> path; //存储每一层的节点值
            //处理每一层的节点
            for(size_t i = 0; i < size; ++i){ //这里不能用que.size()，因为que.size()是变化的
                TreeNode *cur = que.front(); //cur是当前层从左向右的各个节点
                que.pop();
                path.push_back(cur->val);
                //将当前节点的左右孩子加入队列，成为下一层的节点
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            result.push_back(path);
        }
        return result;
    }
};