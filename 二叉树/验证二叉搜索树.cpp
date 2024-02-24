#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) :  val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

//递归 中序遍历  用数组
class Solution {
private:
    //按照中序遍历把二叉树的所有节点值存入数组
    void traversal(TreeNode *root){
        if(root == nullptr) return;
        traversal(root->left);  //左
        vec.push_back(root->val);  //中
        traversal(root->right); //右
    }
public:
    vector<int> vec;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        vec.clear();
        traversal(root);
        //判断数组是否是升序的，不是的话就不是二叉搜索树
        for(size_t i = 0; i < vec.size() - 1; ++i){
            if(vec[i] >= vec[i + 1]) return false;
        }
        return true;
        
    }
};


//递归  中序遍历  不用数组
class Solution {
public:
    TreeNode *pre = nullptr; //记录前一个节点（每一个小子树的根节点）
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        bool left = isValidBST(root->left); //左
        //中
        if(pre != nullptr && pre->val >= root->val) return false; //如果左>=根或根>=右，则不是二叉搜索树
        pre = root; //更新前一个节点
        bool right = isValidBST(root->right);  //右
        return left && right;
    }
};

//迭代  中序遍历
class Solution {
public:
    TreeNode *pre = nullptr; //记录前一个节点（每一个小子树的根节点）
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;  //左
            }
            else{
                cur = st.top();  //中
                st.pop();
                if(pre != nullptr && pre->val >= cur->val) return false; //如果左>=根或根>=右，则不是二叉搜索树
                pre = cur; //更新前一个节点
                cur = cur->right;  //右
            }
        }   
        return true;
    }
};