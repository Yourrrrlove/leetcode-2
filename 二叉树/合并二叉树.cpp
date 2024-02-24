#include <string>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return nullptr;
        if(!root1) return root2;
        if(!root2) return root1;
        TreeNode *root = new TreeNode(root1->val + root2->val); //中
        root->left = mergeTrees(root1->left, root2->left); //左
        root->right = mergeTrees(root1->right, root2->right); //右
        return root;
    }
};