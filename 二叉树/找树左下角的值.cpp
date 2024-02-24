#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

//层序遍历
// class Solution {
// public:
//     int findBottomLeftValue(TreeNode* root) {
//         if(root == nullptr) return 0;
//         queue<TreeNode *> que;
//         que.push(root);
//         int result = 0;
//         while(!que.empty()){
//             int size = que.size();
//             for(size_t i = 0; i < size; ++i){
//                 TreeNode *cur = que.front();
//                 que.pop();
//                 if(i == 0) result = cur->val;  //每一层的第一个节点就是最左边的节点，while循环结束后，result就是最后一层最左边的节点的值，即整棵树最左下角的节点的值
//                 if(cur->left) que.push(cur->left);
//                 if(cur->right) que.push(cur->right);
//             }        
//         }
//         return result;
//     }
// };

//递归
class Solution {
private:
    void traversal(TreeNode *root, int depth){
        if(root->left == nullptr && root->right == nullptr){
            if(depth > maxDepth){  //depth > maxDepth这一判断条件保证了result只记录最深层的节点的值
                maxDepth = depth;
                result = root->val;
            }
            return;
        }
        //前序遍历保证了result只记录每层最左边的节点的值，只要先左后右即可，所以前序遍历和后序遍历都可以
        //要回溯，因为只有遍历完所有路径才知道哪条路径是最深的
        if(root->left) traversal(root->left, depth + 1);  //左
        if(root->right) traversal(root->right, depth + 1); //右
    }
public:
    int maxDepth = INT_MIN, result = 0;
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr) return 0;
        traversal(root, 0);
        return result;
    }
};