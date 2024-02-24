#include <iostream>
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
    void traversal(TreeNode *cur, vector<int> &result){
        if(cur == nullptr) return;
        traversal(cur->left, result); //左
        traversal(cur->right, result); //右
        result.push_back(cur->val); //中
    }
public:
    void deleteTreeNode(TreeNode *root){
        if(root == nullptr) return;
        deleteTreeNode(root->left);
        deleteTreeNode(root->right);
        delete root;
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

int main(){
    Solution s;
    TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    vector<int> ret = s.postorderTraversal(root);
    for(const auto &i : ret){
        cout << i << " ";
    }
    cout << endl;
    s.deleteTreeNode(root);
    return 0;
}