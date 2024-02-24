#include <iostream>
#include <vector>
using namespace std;

//二叉树节点的定义
struct TreeNode{
    int val;  //节点值
    TreeNode *left, *right; //指向左右孩子节点的指针
    //构造函数
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *leftNode, TreeNode *rightNode) : val(x), left(leftNode), right(rightNode){}
};

class Solution {
private:
    void traversal(TreeNode *cur, vector<int> &result){
        if(cur == nullptr) return;
        result.push_back(cur->val); //中
        traversal(cur->left, result); //左
        traversal(cur->right, result); //右
    }
public:
    //删除二叉树的所有节点
    void deleteTreeNode(TreeNode *root){
        if(root == nullptr) return;
        deleteTreeNode(root->left);
        deleteTreeNode(root->right);
        delete root;
    }
    //前序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    vector<int> ret = s.preorderTraversal(root);
    for(const auto &i : ret){
        cout << i << " ";
    }
    cout << endl;
    s.deleteTreeNode(root);
    return 0;
}