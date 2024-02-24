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
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

//递归法  利用完全二叉树的性质
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        TreeNode *left = root->left, *right = root->right;
        int leftDepth = 0, rightDepth = 0;
        //一直向左下角遍历，直到遍历到最左下角的节点
        while(left){
            left = left->left;
            ++leftDepth;
        }
        //一直向右下角遍历，直到遍历到最右下角的节点
        while(right){
            right = right->right;
            ++rightDepth;
        }
        //如果完全二叉树最左下角的节点和最右下角的节点的深度相同，则此完全二叉树是满二叉树，节点数为 2^h - 1
        if(leftDepth == rightDepth) return (2 << leftDepth) - 1;
        //如果不相同，则递归计算左右子树的节点数，在某深度一定能够找到满二叉树（因为叶子节点左右孩子都为空，leftDepth和rightDepth均为0,此时按照完全二叉树返回1）
        return countNodes(left) + countNodes(right) + 1;
    }
};


//迭代法  层序遍历
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode *> que;
        que.push(root);
        int result = 0;
        while(!que.empty()){
            int size = que.size();
            result += size;  //每一层的节点数之和就是总节点数
            for(size_t i = 0; i < size; ++i){
                TreeNode *cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
        }
        return result;
    }
};