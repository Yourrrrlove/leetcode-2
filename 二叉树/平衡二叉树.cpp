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

//平衡二叉树定义为：一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1

class Solution {
private:
    //获取以当前节点为根节点的树的高度
    int getHeight(TreeNode *root){
        if(root == nullptr) return 0; //如果当前节点为空，返回0，表示以当前节点为根节点的树的高度为0
        int leftHeight = 0, rightHeight = 0;
        if(root->left) leftHeight = getHeight(root->left);  //左子树的高度
        if(leftHeight == -1) return -1; //如果左子树的高度为-1，表示以当前节点的左孩子为根节点的树不是平衡二叉树，那么整棵树也不是平衡二叉树，直接返回-1
        if(root->right) rightHeight = getHeight(root->right);  //右子树的高度
        if(rightHeight == -1) return -1;  //如果右子树的高度为-1，表示以当前节点的右孩子为根节点的树不是平衡二叉树，那么整棵树也不是平衡二叉树，直接返回-1
        if(abs(leftHeight - rightHeight) > 1) return -1;  //如果左右子树的高度差大于1，返回-1，表示以当前节点为根节点的树不是平衡二叉树
        return max(leftHeight, rightHeight) + 1; //如果左右子树的高度差小于等于1，返回左右子树中高度较大的值 + 1，表示以当前节点为根节点的树的高度
    }
public:
    bool isBalanced(TreeNode* root) {
        return getHeight(root) == -1 ? false : true;
    }
};