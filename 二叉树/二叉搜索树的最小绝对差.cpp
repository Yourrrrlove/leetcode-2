#include <iostream>
#include <stack>
#include <vector>
#include <climits>
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
    void traversal(TreeNode *root){
        if(root == nullptr) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    vector<int> vec;
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return 0;
        vec.clear();
        traversal(root);
        if(vec.size() == 2) return abs(vec[0] - vec[1]);
        int result = INT_MAX;
        //求相邻两个节点值的差的绝对值的最小值
        for(size_t i = 0; i < vec.size() - 1; ++i){
            result = min(result, abs(vec[i] - vec[i + 1]));
        }
        return result;
    }
};

//递归  中序遍历  不用数组
class Solution {
private:
    void traversal(TreeNode *root){
        if(root == nullptr) return;
        traversal(root->left);
        if(pre != nullptr) result = min(result, abs(pre->val - root->val));
        pre = root;
        traversal(root->right);
    }
public:
    int result = INT_MAX;
    TreeNode *pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return 0;
        traversal(root);
        return result;
    }
};


//迭代  中序遍历
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if(root == nullptr) return 0;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        int result = INT_MAX;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                if(pre != nullptr) result = min(result, cur->val - pre->val);
                pre = cur;
                cur = cur->right;
            }
        }
        return result;
    }
};