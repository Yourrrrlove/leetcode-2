#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

using namespace std;

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(root == nullptr) return root; //遇到空节点, 返回nullptr
        //当前节点的值小于low, 则当前节点及其左子树都不符合要求, 应该返回右子树的修剪结果
        //这一步删除了案例中的节点0,将节点2直接连接到节点3
        if(root->val < low) return trimBST(root->right, low, high);
        //当前节点的值大于high, 则当前节点及其右子树都不符合要求, 应该返回左子树的修剪结果
        if(root->val > high) return trimBST(root->left, low, high);
        root->left = trimBST(root->left, low, high); //用root->left接住修剪后的左子树
        root->right = trimBST(root->right, low, high); //用root->right接住修剪后的右子树
        return root;
    }
};