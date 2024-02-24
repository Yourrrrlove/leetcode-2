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
    //删除二叉树的所有节点
    void deleteTreeNode(TreeNode *root){
        if(root == nullptr) return;
        deleteTreeNode(root->left);
        deleteTreeNode(root->right);
        delete root;
    }
    //前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> result;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode *cur = st.top();
            st.pop();
            result.push_back(cur->val); //中
            //由于栈是先进后出，所以先压入右孩子，再压入左孩子，这样出栈的时候才是中左右
            if(cur->right) st.push(cur->right); //右
            if(cur->left) st.push(cur->left); //左
        }
        return result;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    vector<int> ret = s.preorderTraversal(root);
    for(const auto &i : ret){
        cout << i << " ";
    }
    cout << endl;
    s.deleteTreeNode(root);
    return 0;
}