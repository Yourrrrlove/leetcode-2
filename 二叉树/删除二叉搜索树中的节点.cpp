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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root; //1. 没找到val==key的节点
        //找到了val==key的节点
        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){ //2. 删除的节点是叶子节点, 直接删除, 返回nullptr
                delete root;
                return nullptr;
            }
            //3. 要删除的节点只有一个右子节点, 返回其右子节点
            else if(root->left == nullptr){
                TreeNode *temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            //4. 要删除的节点只有一个左子节点, 返回其左子节点
            else if(root->right == nullptr){
                TreeNode *temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            //5. 要删除的节点root有左右两个子节点, 将root节点的左子树头结点（左孩子）放到root节点的右子树的最左面节点的左孩子上，返回root节点的右孩子为新的根节点
            else{
                TreeNode *cur = root->right;
                while(cur->left != nullptr) cur = cur->left;
                cur->left = root->left;
                TreeNode *temp = root;
                root = root->right;
                delete temp;
                return root;
            }
        }
        //要删除的节点在右子树
        if(root->val < key) root->right = deleteNode(root->right, key);
        //要删除的节点在左子树
        else if(root->val > key) root->left = deleteNode(root->left, key);
        return root;
    }
};