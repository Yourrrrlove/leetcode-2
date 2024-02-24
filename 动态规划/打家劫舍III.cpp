#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    //返回的vector有两个元素，第一个元素表示不偷当前节点的最大收益，第二个元素表示偷当前节点的最大收益
    vector<int> steal(TreeNode* cur){
        if(cur == nullptr) return {0, 0}; //空节点，偷或不偷收益都是0, 返回{0, 0}
        auto left = steal(cur->left); //左子树的收益
        auto right = steal(cur->right); //右子树的收益
        //若偷当前cur节点，则不能偷cur的左右孩子节点
        int value1 = cur->val + left[0] + right[0];
        //若不偷cur节点，则左右孩子节点偷或不偷都可以，取最大值
        int value2 = max(left[0], left[1]) + max(right[0], right[1]); 
        return {value2, value1}; //返回 {不偷cur节点的最大收益, 偷cur节点的最大收益}
    }
public:
    int rob(TreeNode* root) {
        vector<int> result = steal(root);
        return max(result[0], result[1]);
    }
};