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
    TreeNode *traversal(vector<int> &inorder, int inorder_begin, int inorder_end, vector<int> &postorder, int postorder_begin, int postorder_end){
        if(postorder_begin == postorder_end) return nullptr;
        TreeNode *root = new TreeNode(postorder[postorder_end - 1]);  //postorder的最后一个元素是根节点的值，用它来构造根节点
        if(postorder_end - postorder_begin == 1) return root;  //如果postorder只有一个元素，那么这棵树只有根节点，直接返回
        //找到根节点在inorder中的位置
        int index = inorder_begin;
        for(; index < inorder_end; ++index){
            if(inorder[index] == root->val) break;
        }
        //切割inorder数组
        int leftInorderBegin = inorder_begin;  //左闭
        int leftInorderEnd = index;  //右开
        int rightInorderBegin = index + 1;  //左闭
        int rightInorderEnd = inorder_end;  //右开
        //切割postorder数组
        int leftPostorderBegin = postorder_begin;  //左闭
        int leftPostorderEnd = leftPostorderBegin + leftInorderEnd - leftInorderBegin;  //右开
        int rightPostorderBegin = leftPostorderEnd;  //左闭
        int rightPostorderEnd = rightPostorderBegin + rightInorderEnd - rightInorderBegin;  //右开
        //递归 构造左子树
        root->left = traversal(inorder, leftInorderBegin, leftInorderEnd, postorder, leftPostorderBegin, leftPostorderEnd);
        //递归 构造右子树
        root->right = traversal(inorder, rightInorderBegin, rightInorderEnd, postorder, rightPostorderBegin, rightPostorderEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || postorder.size() == 0) return nullptr;
        return traversal(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
};