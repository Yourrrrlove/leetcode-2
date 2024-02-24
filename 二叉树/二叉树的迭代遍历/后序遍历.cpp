#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
    //删除二叉树的所有节点
    void deleteTreeNode(TreeNode *root){
        if(root == nullptr) return;
        deleteTreeNode(root->left);
        deleteTreeNode(root->right);
        delete root;
    }
    //后序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> result;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *cur = st.top();
            st.pop();
            result.push_back(cur->val); //中
            //由于栈是先进后出，先压入左孩子，再压入右孩子，这样出栈的时候得到中右左
            if(cur->left) st.push(cur->left); //左
            if(cur->right) st.push(cur->right); //右
        }
        reverse(result.begin(), result.end()); //将中右左 反转得到 左右中，即后序遍历
        return result;
    }
};