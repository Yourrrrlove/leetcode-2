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


//后序遍历  因为只有先算出左右子树的左叶子的值，才能进行加和来求整棵树的左叶子之和
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return 0;
        int leftval = sumOfLeftLeaves(root->left);  //左  计算以当前节点的左孩子为根节点的树的左叶子之和
        //当前节点的整个左子树就是一个左叶子节点的情况：当前节点左孩子不为空，左孩子的左孩子为空，左孩子的右孩子为空，此时leftval = 当前节点->left->val
        if(root->left && !root->left->left && !root->left->right) leftval = root->left->val;
        int rightval = sumOfLeftLeaves(root->right); //右  计算以当前节点的右孩子为根节点的树的左叶子之和
        return leftval + rightval;   //中 返回左右子树的左叶子之和
    }
};