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

//递归法
// class Solution {
// private:
//     bool compareNode(TreeNode *left, TreeNode *right){
//         if(!left && !right) return true; //左右节点都为空
//         else if(!left && right) return false; //左节点为空，右节点不为空
//         else if(left && !right) return false; //左节点不为空，右节点为空
//         else if(left->val != right->val) return false; //左右节点都不为空，但值不相等
//         else return compareNode(left->left, right->right) && compareNode(left->right, right->left); //左右节点都不为空，且值相等，则递归比较左节点的左子节点和右节点的右子节点以及左节点的右子节点和右节点的左子节点
//     }
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root == nullptr) return true;
//         return compareNode(root->left, root->right);
//     }
// };

//迭代法 栈和队列都可以，把队列原封不动的换成栈就行了
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode *> que;
        que.push(root->left); //左子树的头节点
        que.push(root->right);  //右子树的头节点
        while(!que.empty()){
            //取出左右两节点进行比较
            TreeNode *left = que.front();
            que.pop();
            TreeNode *right = que.front();
            que.pop();
            if(left == nullptr && right == nullptr) continue; //左右节点都为空，则这两节点对称
            if(left == nullptr || right == nullptr || (left->val != right->val)) return false; //左右节点只有一个为空或者都不为空但值不相等，则不对称
            que.push(left->left); //左节点的左子节点
            que.push(right->right); //右节点的右子节点
            que.push(left->right); //左节点的右子节点
            que.push(right->left); //右节点的左子节点
        }
        return true;
    }
};