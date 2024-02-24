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

//递归法 求的是根节点的高度，而根节点的高度就是树的最大深度
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

//迭代法  层序遍历
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode *> que;
        que.push(root);
        int result = 0;
        while(!que.empty()){
            int size = que.size();
            for(size_t i = 0; i < size; ++i){
                TreeNode *cur = que.front();
                que.pop();
                if(cur->left) que.push(cur->left);
                if(cur->right) que.push(cur->right);
            }
            ++result; //每遍历完一层，深度加1
        }
        return result;
    }
};

//递归法  前序遍历求最大深度，而不是求根节点的高度
class Solution {
private:
    void traversal(TreeNode *root, int depth){
        result = depth > result ? depth : result;  //中
        if(root->left == nullptr && root->right == nullptr) return;
        if(root->left) traversal(root->left, depth + 1);  //左
        if(root->right) traversal(root->right, depth + 1);  //右
    }
public:
    int result = 0;
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        traversal(root, 1);
        return result;
    }
};