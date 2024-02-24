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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == nullptr) return root;  //题目说p 和 q 均存在于给定的二叉树中,所以不用担心p或q不存在的情况
        TreeNode *left = lowestCommonAncestor(root->left, p, q); //在左子树中查找p和q
        TreeNode *right = lowestCommonAncestor(root->right, p, q);  //在右子树中查找p和q
        if(left && right) return root; //如果p和q分别在当前root节点的左右子树中，那么root就是p和q的最近公共祖先
        if(!left && right) return right; //如果p和q都在右子树中，那么返回right
        if(left && !right) return left;  //如果p和q都在左子树中，那么返回left
        if(!left && !right) return nullptr;  //如果左右子树中都没有p和q，那么返回nullptr
        return nullptr;
    }
};