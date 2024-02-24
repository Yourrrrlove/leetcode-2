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
        if(p->val > q->val) swap(p, q);  //保证p的值小于q的值
        //如果root的值在p和q之间，那么root就是p和q的最近公共祖先; 如果root为空节点，那么返回nullptr
        if(root->val >= p->val && root->val <= q->val || root == nullptr) return root;
        //如果root的值比p的值还小，那么p和q都在root的右子树中
        if(root->val < p->val) return lowestCommonAncestor(root->right, p, q);
        //如果root的值比q的值还大，那么p和q都在root的左子树中
        if(root->val > q->val) return lowestCommonAncestor(root->left, p ,q);
        return nullptr;
    }
};