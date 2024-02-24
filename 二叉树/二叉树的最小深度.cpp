#include <iostream>
#include <stack>
#include <queue>
#include <climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

//递归法  后序遍历精简版
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        //先算出左右子树的深度
        int leftDepth = minDepth(root->left), rightDepth = minDepth(root->right);
        /*
        最小深度是从根节点到最近叶子节点的最短路径上的节点数量，而左右孩子都为空且自身不为空的节点才是叶子节点，因此：
        如果左子树为空，右子树不为空，说明最小深度是 1 + 右子树的深度
        反之，右子树为空，左子树不为空，最小深度是 1 + 左子树的深度
        最后如果左右子树都不为空，返回左右子树深度最小值 + 1
        */
        if(root->left && !root->right) return 1 + leftDepth;
        if(!root->left && root->right) return 1 + rightDepth;
        return 1 + min(leftDepth, rightDepth);
    }
};

//递归法  前序遍历
class Solution {
private:
    int result = INT_MAX;
    void getDepth(TreeNode *node, int depth){
        if(node == nullptr) return;
        if(node->left == nullptr && node->right == nullptr) result = min(result, depth); //中
        if(node->left) getDepth(node->left, depth + 1);  //左
        if(node->right) getDepth(node->right, depth + 1);  //右
    }
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        getDepth(root, 1);
        return result;
    }
};

//迭代法  层序遍历
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int result = 0;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(size_t i = 0; i < size; ++i){
                TreeNode *cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
                //如果当前节点的左右孩子都为空，说明当前节点是叶子节点，由于是层序遍历，因此本层就是第一个找到叶子节点的层，所以此叶子节点就是深度最小的叶子节点，直接返回它的深度即可
                if(cur->left == nullptr && cur->right == nullptr) return result;
            }
            ++result;
        }
        return result;
    }
};