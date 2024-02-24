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

//右中左 遍历顺序
class Solution {
private:
    int pre = 0;
    void traversal(TreeNode *cur){
        if(cur == nullptr) return;
        //对于每棵树先一路向右找到最右边的节点，按照右中左的顺序遍历累加
        traversal(cur->right); //右
        cur->val += pre; //中
        pre = cur->val;
        traversal(cur->left); //左
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        pre = 0;
        traversal(root);
        return root;
    }
};