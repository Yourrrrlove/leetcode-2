#include <string>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

/*
二叉搜索树是一个有序树：

若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
它的左、右子树也分别为二叉搜索树
*/

//递归
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return nullptr;
        TreeNode *result = nullptr;
        if(root->val > val) result = searchBST(root->left, val); //如果当前节点的值大于val，则在当前节点的左子树中查找
        else if(root->val < val) result = searchBST(root->right, val);  //如果当前节点的值小于val，则在当前节点的右子树中查找
        else result = root;  //如果当前节点的值等于val，则返回当前节点
        return result;
    }
};

//迭代
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr || root->val == val) return root;
        TreeNode *cur = root;
        while(cur){
            if(cur->val > val) cur = cur->left;
            else if(cur->val < val) cur = cur->right;
            else return cur;
        }
        return nullptr;
    }
};