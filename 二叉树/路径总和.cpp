#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

class Solution {
private:
    bool traversal(TreeNode *cur, int sum, int targetSum){
        if(cur->left == nullptr && cur->right == nullptr){ //到了叶子节点，说明一条路径已经走完了
            if(sum == targetSum) return true;  //如果这条路径上的节点之和等于targetSum，则返回true
            return false;  //否则说明这条路径不符合题意，返回false
        }
        bool left = false;  //left标志左子树中是否存在一条路径上的节点之和等于targetSum
        bool right = false; //right标志右子树中是否存在一条路径上的节点之和等于targetSum
        if(cur->left) left = traversal(cur->left, sum + cur->left->val, targetSum); //左
        if(cur->right) right = traversal(cur->right, sum + cur->right->val, targetSum); //右
        return left || right;  //中
    }
public:
    int sum = 0;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        sum = 0;
        return traversal(root, sum + root->val, targetSum);
    }
};


//迭代  前序遍历
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        stack<pair<TreeNode *, int>> st;
        st.push(make_pair(root, root->val));
        while(!st.empty()){
            pair<TreeNode *, int> cur = st.top(); //中
            st.pop();
            if(cur.first->left == nullptr && cur.first->right == nullptr && cur.second == targetSum) return true; //到了叶子节点，且节点之和等于targetSum
            if(cur.first->right) st.push(make_pair(cur.first->right, cur.second + cur.first->right->val));  //右
            if(cur.first->left) st.push(make_pair(cur.first->left, cur.second + cur.first->left->val));  //左
        }
        return false;
    }
};
