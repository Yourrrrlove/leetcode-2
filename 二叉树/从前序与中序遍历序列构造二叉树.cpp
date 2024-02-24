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
private:
    TreeNode *traversal(vector<int>& preorder, int preorderBegin, int preorderEnd, vector<int>& inorder, int inorderBegin, int inorderEnd){
        if(preorderBegin == preorderEnd) return nullptr;
        TreeNode *root = new TreeNode(preorder[preorderBegin]);  //preorder的第一个元素是根节点的值，用它来构造根节点
        if(preorderEnd - preorderBegin == 1) return root; //如果preorder只有一个元素，那么这棵树只有根节点，直接返回
        //找到根节点在inorder中的位置
        int index = inorderBegin;
        for(; index < inorderEnd; ++index){
            if(inorder[index] == root->val) break;
        }
        //切割inorder数组
        int leftInorderBegin = inorderBegin;  //左闭
        int leftInorderEnd = index; //右开
        int rightInorderBegin = index + 1;    //左闭
        int rightInorderEnd = inorderEnd; //右开
        //切割preorder数组
        int leftPreorderBegin = preorderBegin + 1;  //左闭
        int leftPreorderEnd = leftPreorderBegin + leftInorderEnd - leftInorderBegin; //右开
        int rightPreorderBegin = leftPreorderEnd;   //左闭
        int rightPreorderEnd = preorderEnd; //右开
        //递归 构造左子树
        root->left = traversal(preorder, leftPreorderBegin, leftPreorderEnd, inorder, leftInorderBegin, leftInorderEnd);
        //递归 构造右子树
        root->right = traversal(preorder, rightPreorderBegin, rightPreorderEnd, inorder, rightInorderBegin, rightInorderEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || inorder.size() == 0) return nullptr;
        return traversal(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};