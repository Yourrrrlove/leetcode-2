#include <iostream>
#include <vector>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur); //将访问的节点压入栈
                //中序遍历，要先访问最左下位置的左孩子，所以先将指针移动到最左下角的左孩子位置
                cur = cur->left; //左
            }
            else{
                cur = st.top();
                st.pop();
                result.push_back(cur->val); //中
                cur = cur->right; //右
            }
        }
    }
};