#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

class Solution {
public:
    //递归法 前序遍历
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        swap(root->left, root->right); //中
        invertTree(root->left); //左
        invertTree(root->right); //右
        return root;
    }
    //递归法 后序遍历
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;
        invertTree(root->left); //左
        invertTree(root->right); //右
        swap(root->left, root->right); //中
        return root;
    }
    //迭代法 前序遍历
    TreeNode* invertTree(TreeNode* root){
        if(root == nullptr) return root;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *cur = st.top();
            st.pop();
            swap(cur->left, cur->right); //中
            if(cur->right) st.push(cur->right); //右
            if(cur->left) st.push(cur->left); //左
        }
        return root;
    }
    //层序遍历
    TreeNode* invertTree(TreeNode* root){
        if(root == nullptr) return root;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(size_t i = 0; i < size; ++i){
                TreeNode *cur = que.front();
                que.pop();
                swap(cur->left, cur->right);
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return root;
    }
};