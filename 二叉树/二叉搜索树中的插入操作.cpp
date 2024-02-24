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

//递归
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){ //不改变原树结构，而是在合适的空节点处构造新节点并插入
            TreeNode *insertNode = new TreeNode(val);
            return insertNode;
        }
        //如果当前root节点的值大于val，则在左子树中寻找合适的插入位置
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        //如果当前root节点的值小于val，则在右子树中寻找合适的插入位置
        if(root->val < val) root->right = insertIntoBST(root->right, val);
        return root; //返回新插入节点的父节点和原树的根节点
    }
};

//迭代
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){ //如果原树为空，则直接构造新节点并返回
            TreeNode *insertNode = new TreeNode(val);
            return insertNode;
        }
        TreeNode *cur = root, *pre = nullptr;
        while(cur != nullptr){ //寻找合适的插入位置
            pre = cur;
            if(cur->val < val) cur = cur->right;
            else if(cur->val > val) cur = cur->left;
        }
        //while循环结束后cur为空，pre指向新插入节点的父节点
        //根据val的大小构造新节点并插入
        if(pre->val > val) pre->left = new TreeNode(val);
        else if(pre->val < val) pre->right = new TreeNode(val);
        return root;
    }
};